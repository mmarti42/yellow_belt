#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
	bool no_stop;
	string stop;
	vector<string> buses;
};

struct StopsForBusResponse {
	bool no_bus;
	string bus;
	vector<BusesForStopResponse> buses;
};

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
ostream& operator << (ostream& os, const StopsForBusResponse& r);
ostream& operator << (ostream& os, const BusesForStopResponse& r);
