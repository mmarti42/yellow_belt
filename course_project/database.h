#pragma once

#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <functional>

#include "date.h"
#include <set>
#include <list>

std::ostream& operator<< (std::ostream& os, const Date& d);

class Database {
public:
	void Add(const Date& date, const std::string& event);

	void Print(std::ostream& os) const ;

	int RemoveIf(const std::function<bool(const Date&, const std::string&)>& func);

	std::vector<std::pair<Date, std::string> >
	FindIf(const std::function<bool(const Date&, const std::string&)>& func) const ;

	std::string Last(const Date& date) const ;
private:
	std::map<Date, std::pair<std::list<std::set<std::string> :: iterator>, std::set<std::string>> > date_event;
};