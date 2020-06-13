#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

struct	Date
{
	int year;
	int month;
	int day;
};

bool operator ==(const Date& left, const Date& right);

bool operator <(const Date& left, const Date& right);

Date ParseDate(std::istream& is) ;