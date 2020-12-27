#pragma once
#include <iostream>

// Allow rational numbers to work as an alternative to floating point

class Rational
{
// Constructors
public:
	Rational(int numer, int denom);
	Rational(int numer);

// Operator overloads
public:
	Rational operator+(Rational r);
	void operator+=(Rational r);
	Rational operator-(Rational r);
	void operator-=(Rational r);
	Rational operator*(Rational r);
	void operator*=(Rational r);
	Rational operator/(Rational r);
	void operator/=(Rational r);
	void operator=(Rational r);
	bool operator==(Rational r);
	friend std::ostream& operator<<(std::ostream& os, Rational r);

// Functions
public:
	void setNumer(int n);
	void setDenom(int d);
	int getNumer();
	int getDenom();
private:
	void simplify();
	void simplify(Rational r);
	void factorPrime(unsigned short p);
	void factorPrime(Rational r, unsigned short p);

// Data
private:
	int numer = 1;
	int denom = 1;
};

