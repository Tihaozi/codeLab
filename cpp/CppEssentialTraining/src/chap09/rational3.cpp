// madoodia@gmail.com
// conversion operator string + b
#include <iostream>

class Rational {
	int _n;
	int _d;
public:
	Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator){};
	Rational(const Rational & rhs) : _n(rhs._n), _d(rhs._d){};
	~Rational();
	inline int numerator() const {return _n;};
	inline int denominator() const {return _d;};
	Rational & operator = (const Rational &);
	Rational operator + (const Rational &) const;
	Rational operator - (const Rational &) const;
	Rational operator * (const Rational &) const;
	Rational operator / (const Rational &) const;
	operator std::string() const;
};

Rational & Rational::operator = (const Rational & rhs)
{
	if(this != &rhs){
		std::cout << "assignment" << std::endl;
		_n = rhs.numerator();
		_d = rhs.denominator();
	}
	return *this;
}

Rational Rational::operator + (const Rational & rhs) const
{
	return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}
Rational Rational::operator - (const Rational & rhs) const
{
	return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}
Rational Rational::operator * (const Rational & rhs) const
{
	return Rational(_n * rhs._n, _d * rhs._d);
}
Rational Rational::operator / (const Rational & rhs) const
{
	return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational()
{
	std::cout << "destructor: " << _n << '/' << _d << std::endl;
}

Rational::operator std::string() const
{
	const static int max_string = 64;
	char s[max_string];
	snprintf(s, max_string, "%d/%d", _n, _d);
	return std::string(s);
}

std::ostream & operator << (std::ostream & o, const Rational & r)
{
	return o << r.numerator() << "/" << r.denominator();
}

int main(int argc, char *argv[])
{
	using namespace std;

	Rational a = 7;
	cout << "a is " << a << endl;
	Rational b(5, 3);
	cout << "b is " << b << endl;
	Rational c = b;   	// copy constructor
	cout << "c is " << c << endl;
	Rational d;   		// default constructor
	cout << "d is " << d << endl;
	d = c;   			// assignment operator
	cout << "d is " << d << endl;
	Rational & e = d;	// reference
	d = e;				// assignment to self
	cout << "e is " << e << endl;

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;

	string s = "Rational as a string: ";
	s += b;
	cout << s << endl;
	return 0;
}
