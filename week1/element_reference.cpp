#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k)
{
	try {
		m.at(k);
	} catch (exception& r){
		throw runtime_error("No key");
	}
	return m[k];
}

int main ()
{
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
}
