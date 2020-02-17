#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n, stop, j;
	int p = 1;
	string l;
	map<int, vector<string>> list;
	vector<string> verification;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stop;
		for (int w = 0; w < stop; w++) {
			j = 0;
			cin >> l;
			verification.push_back(l);
		}
		for (auto& u : list) {
			if (u.second == verification) {
				cout << "Already exists for " << u.first << endl;
				j = 1;
				break;

			}
		}
		if (j != 1) {
			list[p] = verification;
			cout << "New bus " << p << endl;
			p++;
		 }
		verification.clear();
	}
}