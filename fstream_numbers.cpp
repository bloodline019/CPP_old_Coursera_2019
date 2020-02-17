#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
int main() {
	double n, m;
	int k = 0;
	int out;
	ifstream input("input.txt");
	input >> n >> m;
	int p = n * m;
	for (int i = 1; i <= p; i++) {
		input >> out;
		input.ignore(1);
		cout << setw(10) << out;
		if (i % int(m) == 0) {
			cout << endl;
		}
		else cout << " ";
	}
}
    