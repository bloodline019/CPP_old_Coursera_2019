#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
	int w, q, i;
	cin >> q;
	map <string, vector<string>> list;
	vector<string> busorder, disorder;
	for (w = 0; w < q; ++w) {
		string cmd, bus, stop_name, stop;
		int stop_count;
		vector<string> stops;
		cin >> cmd;
		if (cmd == "NEW_BUS") {
			cin >> bus >> stop_count;
			busorder.push_back(bus);
			for (i = 0; i < stop_count; i++) {
				cin >> stop_name;
				list[bus].push_back(stop_name);	
			}
		}
		else if (cmd == "BUSES_FOR_STOP") {
			cin >> stop;
			int  co = 0;
			for (auto l : list) {
				for (auto s : l.second) {
					if (s == stop) {
						co++;
						disorder.push_back(l.first);
					}
					}
				}
			for (auto z : busorder) {
				for (auto x : disorder) {
					if (z == x) {
						cout << z << " ";
					}
				}
			}
			disorder.clear();
			if (co == 0) {
				cout << "No stop" << endl;
			}
			else
			{
				cout << endl; 
			}

			}
		else if (cmd == "STOPS_FOR_BUS") {
			cin >> bus;
			if (list.end() == list.find(bus))
			{
				cout << "No bus" << endl;
			}
			for (auto j : list[bus])
			{
				cout << "Stop " << j << ": ";
				int co = 0;
				for (auto g : list) {
					for (auto k : g.second) {
						if (k == j && g.first != bus) {
							disorder.push_back(g.first);
							++co;
						}
					}
				}
				for (auto z : busorder) {
					for (auto x : disorder) {
						if (z == x) {
							cout << z << " ";
						}
					}
				}
				disorder.clear();
				if (co == 0)
					cout << "no interchange" << endl;
				else { cout << endl; }
			}
		}
		else if (cmd == "ALL_BUSES") {
			if (list.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (auto l : list) {
					cout << "Bus " << l.first << ": ";
					for (auto s : l.second) {
						cout << s << " ";
					}
					cout << endl;
				}
			}
		}
	}
}

			