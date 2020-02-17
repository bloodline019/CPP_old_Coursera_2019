#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
	Student(string new_name, string new_surname, int new_day, int new_month, int new_year) {
		name = new_name;
	    surname = new_surname;
		day = new_day;
		month = new_month;
		year = new_year;
		}
};
int main() {
	string name, surname, cmd;
	vector<Student> student;
	student.push_back(Student("empty", "empty", 0, 0, 0 ));
	int d, m, y, n, i, p;
	cin >> n;
	for (int q = 1; q <= n; q++) {
		cin >> name >> surname >> d >> m >> y;
		student.push_back(Student(name, surname, d, m, y));
	};
	cin >> p;
	for (int q = 1; q <= p; q++) {
		cin >> cmd >> i;
		if (cmd == "name" && i <= n && i != 0 && n > 0) {
			cout << student[i].name << " " << student[i].surname << endl;
		}
		else if (cmd == "date" && i <= n && i != 0 && n > 0) {
			cout << student[i].day << "." << student[i].month << "." << student[i].year << endl;
		}
		else 
			cout << "bad request" << endl;
	}
	return(0);
}


