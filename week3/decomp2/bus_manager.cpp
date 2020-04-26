#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	for (auto &s : stops) {
		buses_to_stops[bus].push_back(s);
		stops_to_buses[s].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
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

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse r;

	r.buses_to_stops = buses_to_stops;
	return r;
}
