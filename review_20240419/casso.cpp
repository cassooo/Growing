#include<iostream>
#include<string>
using namespace std;

#include"MyMap.h"
#include"MySet.h"

void func(const bit::map<int, int>& m)
{
	//auto mit = m.begin();
	bit::map<int, int>::const_iterator mit = m.begin();
	while (mit != m.end())
	{
		// �����޸�key�������޸�value
		//mit->first = 1;
		//mit->second = 2;

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;
}

int main()
{
	bit::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));

	//bit::map<int, int>::iterator mit = m.begin();
	auto mit = m.begin();
	while (mit != m.end())
	{
		// �����޸�key�������޸�value
		//mit->first = 1;
		mit->second = 2;

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;

	func(m);

	for (const auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	bit::set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(2);
	s.insert(12);
	s.insert(22);
	s.insert(332);
	s.insert(7);
	bit::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// ��Ӧ�������޸�key
	/*	if (*it % 2 == 0)
		{
			*it += 10;
		}*/

		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (const auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	bit::map<string, string> dict;
	dict.insert(make_pair("sort", "xxx"));
	dict["left"]; // ����

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	dict["left"] = "���"; // �޸�
	dict["sort"] = "����"; // �޸�
	dict["right"] = "�ұ�"; // ����+�޸�

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;


	return 0;
}