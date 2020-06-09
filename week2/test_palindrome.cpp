#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

void test()
{
	Assert(IsPalindrom(""), "");
	Assert(IsPalindrom("123321"), "");
	Assert(IsPalindrom("1235321"), "");
	Assert(IsPalindrom("123 321"), "");
	Assert(IsPalindrom("1"), "");
	Assert(IsPalindrom("madam"), "");
	Assert(IsPalindrom("777777"), "");
	AssertEqual(IsPalindrom("777778"), false,"");
	AssertEqual(IsPalindrom("1233521"), false, "");
	AssertEqual(IsPalindrom("123322"), false, "");
	AssertEqual(IsPalindrom("223321"), false, "");
	AssertEqual(IsPalindrom("1 23            321"), false, "");
	AssertEqual(IsPalindrom("123553521"), false, "");
	AssertEqual(IsPalindrom("123123"), false, "");
	AssertEqual(IsPalindrom("Madam"), false, "");
	AssertEqual(IsPalindrom("madam "), false, "");
	AssertEqual(IsPalindrom(" madam"), false, "");
	AssertEqual(IsPalindrom("mada m"), false, "");

}

int main() {
  TestRunner runner;
  runner.RunTest(test, "");
  return 0;
}
