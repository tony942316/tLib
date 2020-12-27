#pragma once

#include "Rational.h"

// To have mathimatical terms such as "(2/3)x^5" work

class Variable
{

// Constructor
public:
	Variable(Rational coef, char var, Rational power);

// Operator Overloads
public:
	Variable operator+(Variable v);
	void operator+=(Variable v);
	Variable operator-(Variable v);
	void operator-=(Variable v);
	Variable operator*(Variable v);
	void operator*=(Variable v);
	Variable operator/(Variable v);
	void operator/=(Variable v);
	friend std::ostream& operator<<(std::ostream& os, Variable v);

// Functions
public:
	Rational getCoef();
	char getVar();
	Rational getPower();

// Data
private:
	Rational coef = 1;
	char var = 'x';
	Rational power = 1;
};

