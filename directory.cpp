#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	map<string, string> list;
		int q;
		string cmd, country, new_capital, old_country_name, new_country_name;
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> cmd;
			if (cmd == "CHANGE_CAPITAL") {
				cin >> country >> new_capital;
				if (list[country] == "") {
					cout << "Introduce new country " << country << " with capital " << new_capital << endl;
				}
				else if (list[country] == new_capital) {
					cout << "Country country hasn't changed its capital" << endl;
				}
				else if (list[country] != new_capital) {
					cout << "Country " << country << " has changed its capital from " << list[country] << " to " << new_capital << endl;
				}
				list[country] = new_capital;
}
			else if (cmd == "RENAME") {
				cin >> old_country_name >> new_country_name;
				if (old_country_name == new_country_name || list.count(old_country_name) == 0 || list.count(new_country_name) == 1) {
					cout << "Incorrect rename, skip";
				}
				else {
					cout << "Country " << old_country_name << " with capital " << list[old_country_name] <<
						" has been renamed to " << new_country_name << endl;
					list[new_country_name] = list[old_country_name];
					list.erase(old_country_name);
				}
			}
			else if (cmd == "ABOUT") {
				cin >> country;
				if (list.count(country) == 0) {
					cout << "Country " << country << " doesn't exist" << endl;
				}
				else {
					cout << "Country " << country << " has capital " << list[country] << endl;
				}
			}
			else if (cmd == "DUMP") {

				if (list.empty()) {
					cout << "There are no countries in the world" << endl;
				}
				else {
					for (const auto& country_item : list) {
						cout << country_item.first << "/" << country_item.second << " ";
					}
					cout << endl;
				}

			}

		}
		return 0;
}