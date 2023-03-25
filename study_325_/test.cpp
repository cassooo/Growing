#include "Data.h"
/*
class Data
{
public:
	Data(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Data(const Data& d)
	{
		_year = d._day;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		cout << "Stack(size_t capacity = 10)" << endl;

		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			exit(-1);
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	Stack(const Stack& st)
	{
		cout << "Stack(const Stack& st)" << endl;
		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			exit(-1);
		}
		memcpy(_array, st._array, sizeof(DataType)*st._size);
		_size = st._size;
		_capacity = st._capacity;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;

		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType *_array;
	size_t    _size;
	size_t    _capacity;
};

class MyQueue
{
public:
	// 默认生成构造
	// 默认生成析构
	// 默认生成拷贝构造
private:
	Stack _pushST;
	Stack _popST;
	int _size = 0;
};

int main()
{
	Data d1(2023, 3, 25);
	d1.Print();

	Data d2(d1);
	d2.Print();

	Stack st1;
	Stack st2(st1);

	cout << "==============================================================" << endl;

	MyQueue q1;
	MyQueue q2(q1);

	return 0;
}
*/

//class Data
//{
//public:
//	Data(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " 年 " << _month << " 月 " << _day << " 日 " << endl;
//	}
//
//	bool operator==(const Data& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	bool operator<(const Data& d)
//	{
//		return _year < d._year
//			|| (_year == d._year && _month < d._month)
//			|| (_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator<=(const Data& d)
//	{
//		return *this < d || *this == d;
//	}
//	bool operator>(const Data& d)
//	{
//		return !(*this <= d);
//	}
//	bool operator>=(const Data& d)
//	{
//		return !(*this < d);
//	}
//	bool operator!=(const Data& d)
//	{
//		return !(*this == d);
//	}
//
//	Data& operator=(const Data& d)	//赋值
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Data& d1, const Data& d2)
//{
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//int main()
//{
//	Data d1(2023, 3, 25);
//	Data d2(2023, 4, 25);
//	Data d3(2023, 5, 25);
//
//	operator==(d1, d2);
//	d1 == d2;	//转换成去调用这个函数operator==(d1, d2);
//	cout << (d1 == d2) << endl;
//
//	d1.operator==(d2);
//	d1 == d2;	//转换成去调用这个函数d1.operator==(d2);
//	cout << (d1 == d2) << endl;
//	d1.Print();
//	d2.Print();
//	cout << "======================================================分隔符" << endl;
//	/*d2 = d1;
//	d1.Print();
//	d2.Print();*/
//	d3 = d2 = d1;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	return 0;
//}

void TestData()
{
	Data d1(2023, 3, 25);
	d1.Print();

	Data d2(2023, 4, 25);
	d2.Print();

	Data d3 = d1;
	d3 += 100;
	d3.Print();
	d1.Print();

	Data d4 = d1 + 100;
	d4.Print();
	d1.Print();
}

int main()
{
	TestData();
	return 0;
}












//#include<iostream>
//using namespace std;

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		cout << "Stack(size_t capacity = 10)" << endl;
//
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType)*st._capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//
//		memcpy(_array, st._array, sizeof(DataType)*st._size);
//		_size = st._size;
//		_capacity = st._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType *_array;
//	size_t    _size;
//	size_t    _capacity;
//};
//
//class MyQueue
//{
//public:
//	// 默认生成构造
//	// 默认生成析构
//	// 默认生成拷贝构造
//
//private:
//	Stack _pushST;
//	Stack _popST;
//	int _size = 0;
//};

//int main()
//{
//	Date d1(2023, 2, 5);
//	d1.Print();
//
//	Date d2(d1);
//	Date d3 = d1; //  拷贝构造
//	d2.Print();
//
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(4);
//
//	Stack st2(st1);
//	cout << "=============================" << endl;
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////
// 运算符重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	// d1 == d2  -》  d1.operator==(d2)
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	// d1 < d2
//	bool operator<(const Date& d)
//	{
//	/*	if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month < d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}*/
//
//		return _year < d._year
//			|| (_year == d._year && _month < d._month)
//			|| (_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	// d1 <= d2
//	bool operator<=(const Date& d)
//	{
//		return *this < d || *this == d;
//	}
//
//	// d1 > d2
//	bool operator>(const Date& d)
//	{
//		return !(*this <= d);
//	}
//
//	bool operator>=(const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	// 返回值为了支持连续赋值，保持运算符的特性
//	// d3 = d1 = d2;
//	// d1 = d1
//	// 17:15继续
//	/*Date& operator=(const Date& d)
//	{
//	if (this != &d)
//	{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//	}
//
//	return *this;
//	}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 2, 4);
//	Date d2(2023, 3, 4);
//	Date d3(2025, 3, 4);
//
//
//	cout << (d1 < d2) << endl;
//
//	d1 = d1;
//	d3 = d1 = d2; // d1.operator=(d2);
//	d1.Print();
//
//	Date d5 = d1; // 拷贝构造
//	Date d6(d1); // 拷贝构造 
//
//
//	//m = i = j = k;
//
//	return 0;
//}

//bool Equal(const Date& x1, const Date& x2)
//bool F1(const Date& x1, const Date& x2)
//bool xiangdeng(const Date& x1, const Date& x2)
//{
//	//...
//}
//
////bool Less(const Date& x1, const Date& x2)
////bool F2(const Date& x1, const Date& x2)
//bool xiaoyu(const Date& x1, const Date& x2)
//
//{
//	//...
//}
//
//int main()
//{
//	Date d1(2023, 2, 4);
//	Date d2(2023, 3, 4);
//	//Equal(d1, d2);
//	//Less(d1, d2);
//
//	return 0;
//}

// 16:10继续
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//int main()
//{
//	Date d1(2023, 2, 4);
//	Date d2(2023, 3, 4);
//
//	cout << operator==(d1, d2) << endl;;
//	cout << (d1 == d2) << endl; // 转换成去调用这个operator==(d1, d2);
//
//	//d1 < d2;
//	//d1 - d2;
//
//	return 0;
//}

//int main()
//{
//	Date d1(2023, 2, 4);
//	Date d2(2023, 3, 4);
//
//	cout << d1.operator==(d2) << endl;;
//	cout << (d1 == d2) << endl; // 转换成去调用这个d1.operator==(d2);
//
//	//d1 < d2;
//	//d1 - d2;
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////
// 
//#include "Date.h"
//
//void TestDate1()
//{
//	Date d1(2023, 2, 4);
//	d1.Print();
//
//	/*Date d2(2023, 2, 29);
//	d2.Print();*/
//
//	Date d2 = d1 + 5000;
//	d2.Print();
//	d1.Print();
//
//	Date d3 = d1;
//	//d1 = d3 += 100;
//	d3 += 100;
//
//	d3.Print();
//	d1.Print();
//
//	int i = 0, j = 0, k = 1;
//	i += j += k;
//}
//
//void TestDate2()
//{
//	Date d1(2023, 2, 4);
//	d1.Print();
//
//	Date d2 = d1 + 100;
//	d2.Print();
//
//	Date d3 = d1 + 100;
//	d3.Print();
//}
//
//void TestDate3()
//{
//	Date d1(2023, 2, 4);
//	d1.Print();
//
//	++d1;  // d1.operator++();
//
//	d1++;  // d1.operator++(0);
//}
//
//int main()
//{
//	TestDate3();
//
//	return 0;
//}