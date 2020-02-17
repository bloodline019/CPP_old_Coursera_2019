#include <iostream>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

class Date {
public:
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		if (new_month > 12 || new_month < 1) {
			stringstream errorstring;
			errorstring << "Month value is invalid: " << new_month;
			throw runtime_error(errorstring.str());
		}
		month = new_month;
		if (new_day > 31 || new_day < 1) {
			stringstream errorstring1;
			errorstring1 << "Day value is invalid: " << new_day;
			throw runtime_error(errorstring1.str());
		}
		day = new_day;
	}
	Date() {}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
	Date(string date_str) {
		string date;
		stringstream ss(date_str);
		ss >> date;
	}
private:
	int year;
	int month;
	int day;
};
ostream& operator<<(ostream& output, const Date& r) {
	char separator = '-';
	output << setfill('0') << setw(4) << r.GetYear() << separator << setw(2) << r.GetMonth() << separator << setw(2) << r.GetDay();
	return output;
}
bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay(); }
		return lhs.GetMonth() < rhs.GetMonth(); }
	return lhs.GetYear() < rhs.GetYear();
}
class BD {
public:
	void Add(Date date, string event) {
		Database[date].insert(event);
	}
	void Del(Date date, string event) {
		if (event == "") {
			cout << "Deleted " << Database[date].size() << " events" << endl;
			Database[date].clear();
		}
		else { 
			bool findevent;
			findevent = 0;
			for (auto& x : Database[date]) {
				if (x == event) {
				cout << "Deleted successfully" << endl;
				findevent = 1;
				break; 
				} 
			}
			if (findevent == 0) {
				cout << "Event not found" << endl;
			}
			Database[date].erase(event);
		}
	}
	void Find(Date date) {
		for (auto& x : Database[date]) {
			cout << x << endl;
		}	
	}
	void Print() {
		for (const auto& x : Database) {
			for (const auto& y : x.second) {
				cout << x.first << " " << y << endl;
			}
		}
	}
private:
	map<Date, set<string>> Database;
};
Date SetDate(const string& date)
{   
	stringstream new_ss(date);
	int year , month , day ;
	char verify = '+' , verify2 = '+';

	new_ss >> year;
	if (new_ss.peek() != '-')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss.ignore(1);
	if (isdigit(new_ss.peek()) || new_ss.peek() == '+' || new_ss.peek() == '-') {
		if (new_ss.peek() == '+' || new_ss.peek() == '-') {
			verify = new_ss.get();
			if (!isdigit(new_ss.peek())) {
				string s = "Wrong date format: " + date;
				throw runtime_error(s);
			}
		}
	} else {
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss >> month;
	if (verify == '-') {
		month *= -1;
	}
	
	if (new_ss.peek() != '-')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss.ignore(1);
	if (isdigit(new_ss.peek()) || new_ss.peek() == '+' || new_ss.peek() == '-') {
		if (new_ss.peek() == '+' || new_ss.peek() == '-') {
			verify2 = new_ss.get();
			if (!isdigit(new_ss.peek())) {
				string s = "Wrong date format: " + date;
				throw runtime_error(s);
			}
		}
	}
	else {
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss >> day;
	if (verify2 == '-') {
		day *= -1;
	}

	if (new_ss.peek() != EOF)
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	return{ year, month, day };
}
int main() {
	BD database;
	string operation;
	string command;
	try {
		while (getline(cin, command)) {
			istringstream in(command);
			in >> operation;
			if (operation == "") {
				continue;
			}
			if (operation == "Add") {
				string date;
				string event;
				in >> date >> event;
				database.Add(SetDate(date), event);
			}
			else if (operation == "Del") {
				string date;
				string event;
				in >> date >> event;
				database.Del(SetDate(date), event);
			}
			else if (operation == "Find") {
				string date;
				in >> date;
				database.Find(SetDate(date));
			}
			else if (operation == "Print") {
				database.Print();
			}
			else if (operation != "Add" || "Del" || "Find" || "Print") {
				cout << "Unknown command: " << operation << endl;
			}
			operation = "";
		}
	}
	catch (exception& x) {
		cout << x.what();
	}
}