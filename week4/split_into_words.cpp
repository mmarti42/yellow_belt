#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> ret;
	auto end = s.begin();

	while (true)
	{
		auto start = end;
		while (end != s.end() && *end != ' ')
			end++;
		ret.push_back({start, end});
		if (end == s.end())
			break;
		end++;
	}
	return ret;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}