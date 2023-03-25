#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month);

	bool operator==(const Data& d);
	bool operator!=(const Data& d);
	bool operator<(const Data& d);
	bool operator<=(const Data& d);
	bool operator>(const Data& d);
	bool operator>=(const Data& d);

	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	int operator-(const Data& d);
	Data& operator++();

	// d1++
	// int参数 仅仅是为了占位，跟前置重载区分
	Data operator++(int);

	Data& operator--();
	Data operator--(int);
private:
	int _year;
	int _month;
	int _day;
};
















//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1);
//	void Print();
//	int GetMonthDay(int year, int month);
//
//	bool operator==(const Date& d);
//	bool operator!=(const Date& d);
//	bool operator<(const Date& d);
//	bool operator<=(const Date& d);
//	bool operator>(const Date& d);
//	bool operator>=(const Date& d);
//
//	Date& operator+=(int day);
//	Date operator+(int day);
//	Date& operator-=(int day);
//
//	// d1 - 100
//	Date operator-(int day);
//
//	// d1 - d2;
//	int operator-(const Date& d);
//
//	// ++d1
//	Date& operator++();
//
//	// d1++
//	// int参数 仅仅是为了占位，跟前置重载区分
//	Date operator++(int);
//private:
//	int _year;
//	int _month;
//	int _day;
//};