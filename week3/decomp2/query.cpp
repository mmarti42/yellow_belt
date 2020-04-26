#include "query.h"

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
