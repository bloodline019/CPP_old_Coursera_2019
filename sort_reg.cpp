#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, i;
	string a;
	vector<string> series;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		series.push_back(a);
	}
	sort(begin(series), end(series), [](const string& l, const string& r) {
		return lexicographical_compare(begin(l), end(l),begin(r), end(r),[](char cl, char cr) { return tolower(cl) < tolower(cr); });});
	for (int j = 0; j < series.size(); j++) {
		cout << series[j] << " ";
	}
	}
