#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_begin == range_end || range_begin + 1 == range_end)
		return ;
	vector< typename RandomIt::value_type > v(range_begin, range_end);
	vector< typename RandomIt::value_type > tmp;
	auto it = v.begin() + v.size() / 3;
	auto it2 = it + v.size() / 3;
	MergeSort(v.begin(), it);
	MergeSort(it, it2);
	MergeSort(it2, v.end());
	merge(v.begin(), it, it, it2, back_inserter(tmp));
	merge(tmp.begin(), tmp.end(), it2, v.end(), range_begin);
}

int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
