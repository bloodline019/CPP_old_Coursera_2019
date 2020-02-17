#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firstname[year] = first_name;
	}
	void ChangeLastName(int year, const string& second_name) {
		secondname[year] = second_name;
	}
	string GetFullName(int year) {
		string actualYearName = "";
		string actualYearSurname = "";
		bool noname = false;
		bool nosurname = false;
		for (const auto& item1 : firstname) {
			if (item1.first <= year) {
				actualYearName = item1.second;
			}
		}
		if (actualYearName == "") {
			noname = true;
		}
		for (const auto& item : secondname) {
			if (item.first <= year) {
				actualYearSurname = item.second;
			}
		}
		if (actualYearSurname == "") {
			nosurname = true;
		}
		if (nosurname == true && noname == true) {
			return "Incognito";
		}
		else if (nosurname == true && noname == false) {
			return actualYearName + " with unknown last name";
		}
		else if (nosurname == false && noname == true) {
			return actualYearSurname + " with unknown first name";
		}
		else return actualYearName + " " + actualYearSurname;
	}
	string GetFullNameWithHistory(int year) {
		vector<string> namebefore;
		vector<string> surnamebefore;
		string nout, sout;
		string actualYearName = "";
		string actualYearSurname = "";
		string nextverify = "";
		bool noname = false;
		bool nosurname = false;
		for (const auto& item : firstname) {
			if (item.first <= year) {
				actualYearName = item.second;
				if (item.second != nextverify) {
					namebefore.push_back(item.second);
					nextverify = item.second;
				}
			}
		}

		if (actualYearName == "") {
			noname = true;
		}
		nextverify = "";
		for (const auto& item : secondname) {
			if (item.first <= year) {
				actualYearSurname = item.second;
				if (item.second != nextverify) {
					surnamebefore.push_back(item.second);
					nextverify = item.second;
				}
			}
		}
		if (namebefore.size() != 0) {
			if (namebefore[namebefore.size() - 1] == actualYearName) {
				namebefore.pop_back();
			}
			reverse(namebefore.begin(), namebefore.end());
			if (namebefore.size() != 0) {
				nout = " (";
			}
			for (int i = 0; i < namebefore.size(); i++) {
				nout += namebefore[i];
				if (i != namebefore.size() - 1) {
					nout += ", ";
				}
				else nout += ")";
			}
		}
		if (surnamebefore.size() != 0 ) {
			if (surnamebefore[surnamebefore.size() - 1] == actualYearSurname) {
				surnamebefore.pop_back();
			}
			reverse(surnamebefore.begin(), surnamebefore.end());
			if (surnamebefore.size() != 0 ) {
				sout = " (";
			}
			for (int i = 0; i < surnamebefore.size(); i++) {
				sout += surnamebefore[i];
				if (i != surnamebefore.size() - 1) {
					sout += ", ";
				}
				else sout += ")";
			}
		}


		if (actualYearSurname == "") {
			nosurname = true;
		}
		if (nosurname == true && noname == true) {
			return "Incognito";
		}
		else if (nosurname == true && noname == false) {
			return  actualYearName + nout + " with unknown last name";
		}
		else if (nosurname == false && noname == true) {
			return  actualYearSurname + sout + " with unknown first name";
		}
		else return  actualYearName + nout + " " + actualYearSurname + sout;
	}
private:
	map<int, string> firstname;
	map<int, string> secondname;
};
int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	return 0;
}
