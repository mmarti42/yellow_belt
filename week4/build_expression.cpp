#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	int x;
	int oper;

	cin >> x >> oper;
	if (oper <= 0)
		cout << x;
	else {
		vector<string> v(oper);

		cin.ignore(1);
		for (int i = 0; i < oper; i++)
			getline(cin, v[i]);
		cout << setw(oper) << setfill('(') << '(';
		cout << x << ") ";
		for (int i = 0; i < oper; i++) {
			cout << v[i];
			if (i + 1 < oper)
				cout << ") ";
		}
	}
	cout << endl;
	return 0;
}