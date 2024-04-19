#pragma once
#include<vector>
#include <string>
using namespace std;

template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};


template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str)
	{
		// BKDR
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};

namespace open_address
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_table.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// ����
			//if ((double)_n / (double)_table.size() >= 0.7)
			if (_n * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() * 2;
				// �����ɱ�����ӳ�䵽�±�
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newSize);

				// �����ɱ�����ݲ��뵽�±���
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST)
					{
						newHT.Insert(_table[i]._kv);
					}
				}

				_table.swap(newHT._table);
			}

			// ����̽��
			HashFunc hf;
			size_t hashi = hf(kv.first) % _table.size();
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}

			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<const K, V>* Find(const K& key)
		{
			// ����̽��
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST
					&& _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];
				}

				++hashi;
				hashi %= _table.size();
			}

			return nullptr;
		}

		// �������
		bool Erase(const K& key)
		{
			HashData<const K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;

				return true;
			}

			return false;
		}

	private:
		vector<HashData<K, V>> _table;
		size_t _n = 0; // �洢��Ч���ݵĸ���
	};
}

// ���ͱ�̣��������ĳ�־������ͣ���Թ㷺������(���ּ�����) -- ģ��
namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	// ǰ������
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, KeyOfT, HashFunc> Self;

		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// ��ǰͰ��û��
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				// ����һ��λ�ò��Ҳ�����һ����Ϊ�յ�Ͱ
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
					{
						++hashi;
					}
				}

				_node = nullptr;
			}

			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};


	// set -> hash_bucket::HashTable<K, K> _ht;
	// map -> hash_bucket::HashTable<K, pair<K, V>> _ht;
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		// ��Ԫ����
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			// �ҵ�һ��Ͱ
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		HashTable()
		{
			_table.resize(10, nullptr);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data)))
			{
				return false;
			}

			HashFunc hf;

			// �������ӵ�1������
			if (_n == _table.size())
			{
				
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				// �����ɱ�˳��ǣ�򣬰ѽڵ�ǣ�����ҵ��±�
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;

						// ͷ�嵽�±�
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}

					_table[i] = nullptr;
				}

				_table.swap(newTable);
			}

			size_t hashi = hf(kot(data)) % _table.size();
			// ͷ��
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		void Print()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				printf("[%d]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				printf("NULL\n");
			}
			cout << endl;
		}

	private:
		vector<Node*> _table; // ָ������
		size_t _n = 0; // �洢�˶��ٸ���Ч����
	};
}