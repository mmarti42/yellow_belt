#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
void print_v(vector<T> v)
{
	bool first = true;
	for (auto& i : v) {
		if (!first)
			cout << ' ';
		first = false;
		cout << i;
	}
	cout << endl;
}

int read_num() {
	int n;

	cin >> n;
	return n;
}

int main() {
	int num = read_num();
	vector<int> v(num);

	for (auto& i : v) {
		i = num--;
	}
	do {
		print_v(v);
	} while(prev_permutation(v.begin(), v.end()));
	return 0;
}