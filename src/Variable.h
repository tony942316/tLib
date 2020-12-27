#pragma once

#include "Rational.h"

class Variable
{
public:
	Variable(Rational coef, char var, Rational power);
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
public:
	Rational getCoef();
	char getVar();
	Rational getPower();
private:
	Rational coef = 1;
	char var = 'x';
	Rational power = 1;
};

