#include <iostream>
#include <vector>
using namespace std;
int main() {
	int64_t n;
	vector<int64_t> days;
	int64_t sum = 0;
	cin >> n;
	for (int64_t i = 0; i < n; i++) {
		int64_t k;
		cin >> k;
		sum += k;
		days.push_back(k);
	}
	int64_t out = sum / n;
	int64_t i = 0, k = 0;
	bool first = 0;
	for (auto& x : days) {
		if (x > out) {
			k++;
		}
	}
		cout << k << endl;
	for (auto& x : days) {
		if (x > out) {
			cout << i << " ";
		}
		i++;
	}
}