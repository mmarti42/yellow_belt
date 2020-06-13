#pragma once

#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <functional>

#include "date.h"

std::ostream& operator<< (std::ostream& os, const Date& d);

class Database {
public:
	void Add(const Date& date, const std::string& event);

	void Print(std::ostream& os);

	int RemoveIf(const std::function<bool(const Date&, const std::string&)>& func);

	std::vector<std::pair<Date, std::string> >
	FindIf(const std::function<bool(const Date&, const std::string&)>& func) const ;

	std::pair<const Date, const std::string> Last(const Date& date) const ;
private:
	std::map<Date, std::vector<std::string> > date_event;
	//std::map<std::string, Date> event_date;
};