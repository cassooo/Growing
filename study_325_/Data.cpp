#include "Data.h"

int Data::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Data::Data(int year, int month, int day)
{
	if (month > 0 && month < 13
		&& (day > 0 && day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}

void Data::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Data::operator==(const Data& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Data::operator<(const Data& d)
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}
bool Data::operator<=(const Data& d)
{
	return *this < d || *this == d;
}
bool Data::operator>(const Data& d)
{
	return !(*this <= d);
}
bool Data::operator>=(const Data& d)
{
	return !(*this < d);
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);
}
Data& Data::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
Data Data::operator+(int day)
{
	Data tmp(*this);
	tmp += day;
	return tmp;
}
/*
Data Data::operator+(int day)
{
	Data tmp(*this);

	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}
Data& Data::operator+=(int day)
{
	*this = *this + day;
	return *this;
}
*/
Data& Data::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Data Data::operator-(int day) 
{
	Data tmp(*this);
	tmp -= day;
	return tmp;
}

 //++d1
Data& Data::operator++()
{
	*this += 1;
	return *this;
}

// d1++
Data Data::operator++(int)
{
	Data tmp(*this);
	*this += 1;
	return tmp;
}

Data& Data::operator--()
{
	*this -= 1;
	return *this;
}

// d1-- -> d1.operator--(1)
Data Data::operator--(int)
{
	Data tmp(*this);
	*this -= 1;

	return tmp;
}

int Data::operator-(const Data& d) 
{
	Data max = *this;
	Data min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}












//#include"Date.h"

//int Date::GetMonthDay(int year, int month)
//{
//	assert(month > 0 && month < 13);
//
//	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return monthArray[month];
//	}
//}
//
//Date::Date(int year, int month, int day)
//{
//	if (month > 0 && month < 13
//		&& (day > 0 && day <= GetMonthDay(year, month)))
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	else
//	{
//		cout << "ڷǷ" << endl;
//	}
//}
//
//void Date::Print()
//{
//	cout << _year << "/" << _month << "/" << _day << endl;
//}
//
//bool Date::operator==(const Date& d)
//{
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//
//// d1 < d2
//bool Date::operator<(const Date& d)
//{
//	return _year < d._year
//		|| (_year == d._year && _month < d._month)
//		|| (_year == d._year && _month == d._month && _day < d._day);
//}
//
//// d1 <= d2
//bool Date::operator<=(const Date& d)
//{
//	return *this < d || *this == d;
//}
//
//// d1 > d2
//bool Date::operator>(const Date& d)
//{
//	return !(*this <= d);
//}
//
//bool Date::operator>=(const Date& d)
//{
//	return !(*this < d);
//}
//
//bool Date::operator!=(const Date& d)
//{
//	return !(*this == d);
//}
//
//Date& Date::operator+=(int day)
//{
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (_month == 13)
//		{
//			++_year;
//			_month = 1;
//		}
//	}
//
//	return *this;
//}

// d1 + 100
//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//
//	tmp += day;
//
//	return tmp;
//}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month == 13)
//		{
//			++tmp._year;
//			tmp._month = 1;
//		}
//	}
//
//	return tmp;
//}
//
//// d1 += 100
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//
//	return *this;
//}

// ++d1
//Date& Date::operator++()
//{
//	*this += 1;
//	return *this;
//}
//
//// d1++
//Date Date::operator++(int)
//{
//	Date tmp(*this);
//
//	*this += 1;
//
//	return tmp;
//}