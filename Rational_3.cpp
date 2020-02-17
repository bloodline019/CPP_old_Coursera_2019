#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	};
	Rational(int new_numerator, int new_denominator) {
		if (new_denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
		int nod = Nod(abs(new_numerator), abs(new_denominator));
		if (new_numerator < 0 && new_denominator < 0) {
			nod *= -1;
		}
		else if (new_denominator < 0 && new_numerator > 0) {
			new_numerator *= -1;
			new_denominator *= -1;
		}
		numerator = new_numerator / nod;
		denominator = new_denominator / nod;
		if (numerator == 0) {
			denominator = 1;
		}
	};
	int Numerator() const {
		return numerator;
	};
	int Denominator() const {
		return denominator;
	};
private:
	int numerator; //числитель
	int denominator; //знаменатель
	int Nod(int a, int b) { //маленькая функция нахождения делителя
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}
};
Rational operator + (Rational a, Rational b) {
	int p = (a.Numerator()*b.Denominator()) + (b.Numerator() * a.Denominator());
	int q = a.Denominator() * b.Denominator();
	return Rational(p, q);
}
Rational operator - (Rational a, Rational b) {
	int p = (a.Numerator()*b.Denominator()) - (b.Numerator() * a.Denominator());
	int q = a.Denominator() * b.Denominator();
	return Rational(p, q);
}
bool operator == (Rational a, Rational b) {
	if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator())) {
		return true;
	}
	else {
		return false;
	}
}
Rational operator * (Rational a, Rational b) {
	int p = (a.Numerator()*b.Numerator());
	int q = (a.Denominator() * b.Denominator());
	return Rational(p, q);
}
Rational operator / (Rational a, Rational b) {
	int p = (a.Numerator()*b.Denominator());
	int q = (a.Denominator() * b.Numerator());
	if (q == 0) {
		throw domain_error("Division by zero");
	}
	return Rational(p, q);
}
istream& operator >> (istream& stream, Rational& r) { //возвращать будем ссылку на поток
	//if (stream) return stream;
	int p, q;
	if (stream >> p && stream.ignore(1) && stream >> q) {
		r = { p, q };
	}
	return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}
bool operator > (Rational a, Rational b) {
	return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) { 
	return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}
int main() {
	string operation;
	Rational fraction1, fraction2;
	try {
		cin >> fraction1 >> operation >> fraction2;
	}
	catch (invalid_argument&) {
		cout << "Invalid argument" << endl;
		return 1;
	}
	if (operation == "+") {
		cout << fraction1 + fraction2;
	}
	else if (operation == "-") {
		cout << fraction1 - fraction2;
	}
	else if (operation == "*") {
		cout << fraction1 * fraction2;
	}
	else if (operation == "/") {
		try {
			fraction1 / fraction2;
		} 
		catch (domain_error&) {
			cout << "Division by zero";
			return 2;
			}
		cout << fraction1 / fraction2;
	}
}