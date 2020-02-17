#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	};
	Rational(int new_numerator, int new_denominator) {
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
int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}
	cout << "OK" << endl;
	return 0;
}