#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n, q = 0, i;
	string s;
	string cmd;
	vector<int> days {32,29,32,31,32,31,32,32,31,32,31,32};
	vector<string> month(days[q]);
	vector<int> count(days[q]);
	cin >> n;
	while (n != 0) {
		cin >> cmd;
		if (cmd == "ADD") {
			cin >> i >> s;
			if (month[i] != "") {
				month[i] += " ";
			}
			month[i] += s;
			count[i] += 1;
			n--;
		}
		else if (cmd == "NEXT") {
			if (q == 11) {
				q = 0;
				month.resize(days[q]);
				count.resize(days[q]);
			} else {
				q++;
			if (days[q] >= days[q - 1]) {
				month.resize(days[q]);
				count.resize(days[q]);
			} else {
				for (int i = days[q - 1] - 1; i <= days[q - 1] - 1 && i > days[q]; i--) {
					if (month[i] != "") {
						if (month[days[q]-1] != "") {
							month[days[q]-1] += " ";
						}
						month[days[q]-1] += month[i];   
						month[i] = "";
						count[i] = 0;
						count[days[q]-1] += 1;
					}
				}
				month.resize(days[q]);
				count.resize(days[q]);
			}
		}
			n--;
		}
		else if (cmd == "DUMP") {
			cin >> i;
			cout << count[i] << " " << month[i] << endl;
			n--;
}
}
}