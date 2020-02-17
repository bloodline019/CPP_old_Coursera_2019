#include <set>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, set<string>> list;
		int q, c;
		string cmd, word1, word2, word;
		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> cmd;
			if (cmd == "ADD") {
				cin >> word1 >> word2;
				list[word1].insert(word2);
				list[word2].insert(word1);
			}
			else if (cmd == "COUNT") {
				cin >> word;
				c = list[word].size();
				cout << c << endl;
			}
			else if (cmd == "CHECK") {
				int w = 0;
				cin >> word1 >> word2;
				for (auto& c : list[word1]) {
					if (c == word2) {
						w = 1;
						cout << "YES" << endl;
						break;
					}
				}
					if (w == 0) {
						cout << "NO" << endl;
					}
				}
			}

	}







