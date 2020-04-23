#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi);

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m);

template <typename Key, typename Value>
map<Key, Value> operator *(map<Key, Value> m1, map<Key, Value> m2);

template <typename T>
vector<T> operator *(vector<T> v1, vector<T> v2);

template <typename First, typename Second>
pair<First, Second> operator *(pair<First, Second>& p, pair<First, Second> &p2);

template <typename Collection>
Collection Sqr(Collection& c);

template <typename Collection>
string Join(const Collection& c, char d) {
	stringstream ss;
	bool first = true;
	for (const auto& i : c) {
		if (!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
	return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
	return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
	return out << '{' << Join(m, ',') << '}';
}

template <typename First, typename Second>
pair<First, Second> operator *(pair<First, Second>& p, pair<First, Second> &p2)
{
	First f = p.first * p2.first;
	Second s = p.second * p2.second;
	return make_pair(f, s);
}

template <typename Key, typename Value>
map<Key, Value> operator *(map<Key, Value> m1, map<Key, Value> m2)
{
	map<Key, Value> ret;

	for (auto i : m1) {
		ret[i.first] = m1[i.first] * m2[i.first];
	}
	return ret;
}

template <typename T>
vector<T> operator *(vector<T> v1, vector<T> v2)
{
	vector<T> ret;

	for (int i = 0; i < v1.size() && i < v2.size(); i++) {
		ret.push_back(v1[i] * v2[i]);
	}
	return (ret);
}

template <typename Collection>
Collection Sqr(Collection& c)
{
	return c * c;
}


int main()
{
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
			{4, {2, 2}},
			{7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
