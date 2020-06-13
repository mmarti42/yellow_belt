#include "database.h"
using namespace std;

void Database::Add(const Date &date, const string &event) {
	auto& p = date_event[date];

	if (!p.second.count(event)) {
		p.first.push_back(p.second.insert(event).first);
	}
}

void Database::Print(ostream& os) const {
	for (const auto& item : date_event) {
		for (const auto& i : item.second.first) {
			os << item.first << " " << *i;
			os << endl;
		}
	}
}

int Database::RemoveIf(const std::function<bool(const Date &, const std::string &)>& func) {
	int count = 0;

	for (auto it = date_event.begin(); it != date_event.end();) {
		for (auto itv = it->second.first.begin() ; itv != it->second.first.end() ; ) {
			if (func(it->first, **itv)) {
				count++;
				auto tmp = *itv;
				itv = it->second.first.erase(itv);
				it->second.second.erase(tmp);
			} else {
				itv++;
			}
		}
		if (it->second.first.empty()) {
			it = date_event.erase(it);
		} else {
			it++;
		}
	}
	return count;
}

std::vector<std::pair<Date, std::string> >
Database::FindIf(const std::function<bool(const Date &, const std::string &)> &func) const {
	vector<pair<Date, string> > v;

	for (const auto& item : date_event) {
		for (const auto& i : item.second.first) {
			if (func(item.first, *i)) {
				v.emplace_back(item.first, *i);
			}
		}
	}
	return v;
}

string to_string(const Date& d) {
	ostringstream s;

	s << d;
	return s.str();
}

string Database::Last(const Date &date) const {
	if (date_event.empty() || date < date_event.begin()->first)
		throw (invalid_argument("No entries"));
	auto it = date_event.upper_bound(date);
	it--;
	return {to_string(it->first) + " " + *it->second.first.back()};
}
