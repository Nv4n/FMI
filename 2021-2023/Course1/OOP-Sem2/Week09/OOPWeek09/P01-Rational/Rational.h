#ifndef RATIONAL_H
#define RATIONAL_H


#pragma once
class Rational {
private:
	int numerator;
	int denominator;

	static int sign(const int);
	static int gcd(int a, int b);

public:

	Rational();
	Rational(const int, const int);

	Rational negate() const;
	Rational reciprocal() const;

	Rational add(const Rational& that) const;
	Rational subtract(const Rational& that) const;
	Rational multiply(const Rational& that) const;
	Rational divide(const Rational& that) const;

	void print() const;

	friend Rational operator+(const Rational& lrv, const Rational& rrv);
	friend Rational& operator+=(Rational& lrv, const Rational& rrv);
	friend Rational operator-(const Rational& lrv, const Rational& rrv);
	friend Rational& operator-=(Rational& lrv, const Rational& rrv);

	friend Rational operator*(const Rational& lrv, const Rational& rrv);
	friend Rational& operator*=(Rational& lrv, const Rational& rrv);
	friend Rational operator/(const Rational& lrv, const Rational& rrv);
	friend Rational& operator/=(Rational& lrv, const Rational& rrv);

	friend bool operator==(const Rational& lrv, const Rational& rrv);
	friend bool operator!=(const Rational& lrv, const Rational& rrv);
	friend bool operator>(const Rational& lrv, const Rational& rrv);
	friend bool operator<(const Rational& lrv, const Rational& rrv);
	friend bool operator<=(const Rational& lrv, const Rational& rrv);
	friend bool operator>=(const Rational& lrv, const Rational& rrv);
};
#endif // !RATIONAL_H
