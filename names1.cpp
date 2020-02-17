#include <string>
#include <map>
#include <algorithm>
#include <iostream>
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
private:
	map<int, string> firstname;
	map<int, string> secondname;
};
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}