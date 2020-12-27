#include "Variable.h"

Variable::Variable(Rational coef, char var, Rational power)
	:
	coef(coef),
	var(var),
	power(power)
{
}

Variable Variable::operator+(Variable v)
{
	if (power == v.getPower() && var == v.getVar())
	{
		Variable n = Variable(coef + v.getCoef(), var, power);
		return n;
	}
}

Rational Variable::getCoef()
{
	return coef;
}

char Variable::getVar()
{
	return var;
}

Rational Variable::getPower()
{
	return power;
}

std::ostream& operator<<(std::ostream& os, Variable v)
{
	if (v.getCoef() != 1)
	{
		os << v.getCoef();
	}

	os << v.getVar();

	if (v.getPower() != 1)
	{
		os << "^(" << v.getPower() << ")";
	}
	os << v.getCoef() << v.getVar() << "^(" << v.getPower() << ")";
	return os;
}
