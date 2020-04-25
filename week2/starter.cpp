#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string input;

  q.stops.resize(0);
  is >> input;
  if (input == "NEW_BUS")
  {
  	int c;

  	q.type = QueryType::NewBus;
  	is >> q.bus;
	is >> c;
	while (c--)
	{
		string tmp;

		cin >> tmp;
		q.stops.push_back(tmp);
	}
  }
  else if (input == "BUSES_FOR_STOP") {
	  q.type = QueryType::BusesForStop;
	  cin >> q.stop;
  }
  else if (input == "STOPS_FOR_BUS") {
	  q.type = QueryType::StopsForBus;
	  cin >> q.bus;
  }
  else if (input == "ALL_BUSES")
	  q.type = QueryType::AllBuses;
  return is;
}

struct BusesForStopResponse {
	bool no_stop;
	string stop;
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.no_stop) {
  	os << "No stop";
  } else {
  	bool f = true;
  	for (auto& i : r.buses) {
  		if (!f) {
  			os << ' ';
  		}
  		f = false;
  		os << i;
  	}
  }
  return os;
}

struct StopsForBusResponse {
	bool no_bus;
	string bus;
	vector<BusesForStopResponse> buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.no_bus) {
		os << "No bus";
	} else {
		bool f = true;
		for (auto i : r.buses) {
			if (!f) {
				os << endl;
			}
			f = false;
			os << "Stop " << i.stop << ":";
			if (i.buses.size() == 1) {
				os << " no interchange";
			} else {
				for (auto s : i.buses) {
					if (s != r.bus)
						os << ' ' << s;
				}
			}
		}
	}

  return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.size() == 0){
		os << "No buses";
	} else {
		bool f = true;
		for (auto i : r.buses_to_stops) {
			if (!f) {
				os << endl;
			}
			f = false;
			os << "Bus " << i.first << ':';
			for (auto s : i.second) {
				os << ' ' << s;
			}
		}
	}
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    for (auto& s : stops)
	{
    	buses_to_stops[bus].push_back(s);
    	stops_to_buses[s].push_back(bus);
	}
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    BusesForStopResponse r;

    if (stops_to_buses.count(stop)) {
    	r.stop = stop;
    	r.no_stop = false;
    	r.buses = stops_to_buses.at(stop);
    }
    else
    	r.no_stop = true;
    return r;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse r;

    if (buses_to_stops.count(bus))
	{
    	r.no_bus = false;
    	r.bus = bus;
    	vector<string> v = buses_to_stops.at(bus);
    	for (auto& i : v)
    		r.buses.push_back(GetBusesForStop(i));
	} else {
		r.no_bus = true;
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
  	AllBusesResponse r;

  	r.buses_to_stops = buses_to_stops;
  	return r;
  }

private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
