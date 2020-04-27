#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_begin == range_end || range_begin + 1 == range_end)
		return ;
	vector< typename RandomIt::value_type > v(range_begin, range_end);
	auto it = v.begin() + v.size() / 2;
	MergeSort(v.begin(), it);
	MergeSort(it, v.end());
	merge(v.begin(), it, it, v.end(), range_begin);
}

int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
