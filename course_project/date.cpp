#include "date.h"

using namespace std;

bool operator ==(const Date& left, const Date& right) {
	return left.year == right.year && left.month == right.month && left.day == right.day;
}

bool operator <(const Date& left, const Date& right) {
	if (left.year != right.year)
		return (left.year < right.year);
	else if (left.month != right.month)
		return left.month < right.month;
	else
		return (left.day < right.day);
}


ostream& operator<< (ostream& os, const Date& d) {
	os << setw(4) << setfill('0') << d.year << '-' << setw(2) << d.month << '-' << setw(2) << d.day;
	return os;
}

Date ParseDate(istringstream& is) {
	int year;
	int month;
	int day;

	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;
	return {year, month, day};
}
