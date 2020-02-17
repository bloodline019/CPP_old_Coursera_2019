#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>
using namespace std;
class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	};
	Rational(int new_numerator, int new_denominator) {
		if (new_denominator == 0) {
			throw invalid_argument("invalid_argument");
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
Rational operator / (Rational a, Rational b) {
	int p = (a.Numerator()*b.Denominator());
	int q = (a.Denominator() * b.Numerator());
	if (q == 0) {
		throw domain_error("domain_error");
	}
	return Rational(p, q);
}
int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument& ) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error& ) {
	}

	cout << "OK" << endl;
	return 0;
}