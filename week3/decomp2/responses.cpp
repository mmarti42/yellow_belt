#include "responses.h"

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
