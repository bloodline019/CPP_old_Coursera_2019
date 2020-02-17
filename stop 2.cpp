#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main(){
	int q, bus_stops_count;
	map<int, vector<string>> bus_routes;
	vector<string> bus_stops;
	string stop;
	for (int i = 0; i < q; i++) { // Цикл на количество вводимых команд.
		cin >> bus_stops_count;
		for (int j = 0; j < bus_stops_count; j++) {
			cin >> stop;
			bus_stops.push_back(stop);	
		}
		int isTrue = 0;
			isTrue = bus_routes[bus_stops];
	}
return 0;
}

