#include "database.h"
using namespace std;

void Database::Add(const Date &date, const string &event) {

	try {
		vector<string>& v = date_event.at(date);
		if (find(v.begin(), v.end(), event) == v.end())
			v.push_back(event);
	} catch (exception& e) {
		date_event[date].push_back(event);
	}
	//event_date[event] = date;
}

void Database::Print(ostream& os) {
	for (const auto& item : date_event) {
		os << item.first;
		for (const auto& i : item.second) {
			os << " " << i;
		}
		os << endl;
	}
}

int Database::RemoveIf(const std::function<bool(const Date &, const std::string &)>& func) {
	int count = 0;

	for (auto it = date_event.begin(); it != date_event.end();) {
		for (auto itv = it->second.begin(); itv != it->second.end();) {
			if (func(it->first, *itv)) {
				count++;
				itv = it->second.erase(itv);
				if (it->second.empty()) {
					it = date_event.erase(it);
					break ;
				}
			} else {
				itv++;
			}
		}
		if (it != date_event.end())
			it++;
	}
	return count;
}

std::vector<std::pair<Date, std::string> >
Database::FindIf(const std::function<bool(const Date &, const std::string &)> &func) const {
	vector<pair<Date, string> > v;

	for (const auto& item : date_event) {
		for (const auto& i : item.second) {
			if (func(item.first, i)) {
				v.emplace_back(item.first, i);
			}
		}
	}
	return v;
}

	std::pair<const Date, const std::string> Database::Last(const Date &date) const {
	auto it = date_event.begin();

	if (date < it->first)
		throw (invalid_argument("No entries"));
	while (!(date < it->first || date == it->first) && it != date_event.end())
		it++;
	it--;
	return {it->first, it->second.back()};
}
