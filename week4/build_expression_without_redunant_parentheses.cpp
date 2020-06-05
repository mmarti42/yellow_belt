#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;

void add_par(list<string>& l)
{
	l.front() = '(' + l.front();
	l.back() += ')';
}

int main()
{
	int x;
	int oper;
	int last_priority = 1;
	list<string> l;

	cin >> x >> oper;
	l.push_back(to_string(x));
	cin.ignore(1);
	while (oper--)
	{
		int current_priority;
		string s;

		getline(cin, s);
		current_priority = (s[0] == '*' || s[0] == '/') ? 1 : 0;
		if (current_priority > last_priority)
			add_par(l);
		l.push_back(s);
		last_priority = current_priority;
	}
	for (const auto& item : l) {
		cout << item << ' ';
	}
	cout << endl;
	return 0;
}