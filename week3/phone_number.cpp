#include "phone_number.h"
#include <exception>
#include <vector>
#include <sstream>
#include <iostream>

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

PhoneNumber::PhoneNumber(const string &international_number) {
	stringstream ss(international_number);

	if (ss.get() != '+')
		throw invalid_argument("i");
	getline(ss, country_code_, '-');
	if (!country_code_.size())
		throw invalid_argument("i");
	getline(ss, city_code_,'-');
	if (!city_code_.size())
		throw invalid_argument("i");
	ss >> local_number_;
	if (!local_number_.size() || !ss.eof())
		throw invalid_argument("i");
}

int main()
{
	PhoneNumber p("+7-918-822-0000");

	cout << p.GetCountryCode() << endl << p.GetCityCode() << endl << p.GetLocalNumber() << endl << p.GetInternationalNumber() << endl;
	return 0;
}