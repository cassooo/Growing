#pragma once
#include"RBTree.h"

namespace bit
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}

		// iterator RBTree::const_iterator
		pair<iterator, bool> insert(const K& key)
		{
			// pair<RBTree::iterator, bool>
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}