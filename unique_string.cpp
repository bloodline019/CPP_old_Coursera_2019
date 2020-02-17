#include <set>
#include <string>
#include <map>
using namespace std;
set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> s;
	for (auto i : m) {
		s.insert(i.second);
	}
	return s;
}