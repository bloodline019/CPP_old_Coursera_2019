#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> busesByStops;
	map<string, vector<string>> stopsByBuses;

	for (int i = 0; i < q; ++i) {
		string cmd;
		cin >> cmd;

		if (cmd == "NEW_BUS") {
			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;
			for (int j = 0; j < stop_count; ++j) {
				string stop;
				cin >> stop;
				stopsByBuses[bus].push_back(stop);
				busesByStops[stop].push_back(bus);

			}
		}
		if (cmd == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			if (busesByStops.count(stop) == 0) {
				cout << "No stop";
			}
			else {
				for (const auto& bus : busesByStops[stop]) {
					cout << bus << " ";
				}
			}
			cout << endl;
		}

		if (cmd == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (stopsByBuses.count(bus) == 0) {
				cout << "No bus" << endl;
			}
			else {
			for (const auto& stop : stopsByBuses[bus]) {
				cout << "Stop " << stop << ": ";
				if (busesByStops[stop].size() == 1) {
					cout << "no interchange" << endl;
				}
				else {
					for (const auto& busItem : busesByStops[stop]) {
						if (busItem == bus) {
							continue;
						}
						cout << busItem << " ";
					}
					cout << endl;
				}
			}
		}
	}

		if (cmd == "ALL_BUSES") {
			if (stopsByBuses.size() == 0) {
				cout << "No buses" << endl;
			}
			for (const auto& item : stopsByBuses) {
				cout << "Bus " << item.first << ": ";
				for (const auto& stop : item.second) {
					cout << stop << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}