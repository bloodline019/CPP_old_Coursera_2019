#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& s) {
		String = s;
	}
	void Reverse() {
		reverse(begin(String), end(String));
	}
	string ToString() const {
		return String;
	}
private:
	string String;
};