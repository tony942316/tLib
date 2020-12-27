#include "Rational.h"

Rational::Rational(int numer, int denom)
	:
	numer(numer),
	denom(denom)
{
	simplify();
}

Rational::Rational(int numer)
	:
	numer(numer),
	denom(1)
{
}

Rational Rational::operator+(Rational r)
{
	if (denom == r.getDenom())
	{
		Rational num = Rational(numer + r.getNumer(), denom);
		simplify(num);
		return num;
	}
	else
	{
		Rational num = Rational((numer * r.getDenom()) + (denom * r.getNumer()), (denom * r.getDenom()));
		simplify(num);
		return num;
	}
}

void Rational::operator+=(Rational r)
{
	if (denom == r.getDenom())
	{
		numer += r.getNumer();
		simplify();
	}
	else
	{
		numer = (numer * r.getDenom()) + (denom * r.getNumer());
		denom *= r.getDenom();
		simplify();
	}
}

Rational Rational::operator-(Rational r)
{
	if (denom == r.getDenom())
	{
		Rational num = Rational(numer - r.getNumer(), denom);
		simplify(num);
		return num;
	}
	else
	{
		Rational num = Rational((numer * r.getDenom()) - (denom * r.getNumer()), (denom * r.getDenom()));
		simplify(num);
		return num;
	}
}

void Rational::operator-=(Rational r)
{
	if (denom == r.getDenom())
	{
		numer -= r.getNumer();
		simplify();
	}
	else
	{
		numer = (numer * r.getDenom()) - (denom * r.getNumer());
		denom *= r.getDenom();
		simplify();
	}
}

Rational Rational::operator*(Rational r)
{
	Rational num = Rational(numer * r.getNumer(), denom * r.getDenom());
	simplify(num);
	return num;
}

void Rational::operator*=(Rational r)
{
	numer *= r.getNumer();
	denom *= r.getDenom();
	simplify();
}

Rational Rational::operator/(Rational r)
{
	Rational num = Rational(numer * r.getDenom(), denom * r.getNumer());
	simplify(num);
	return num;
}

void Rational::operator/=(Rational r)
{
	numer *= r.getDenom();
	denom *= r.getNumer();
	simplify();
}

void Rational::operator=(Rational r)
{
	numer = r.getNumer();
	denom = r.getDenom();
}

bool Rational::operator==(Rational r)
{
	if (numer == r.getNumer() && denom == r.getDenom())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, Rational r)
{
	if (r.getDenom() != 1)
	{
		os << r.getNumer() << '/' << r.getDenom();
	}
	else
	{
		os << r.getNumer();
	}
	return os;
}

void Rational::setNumer(int n)
{
	numer = n;
}

void Rational::setDenom(int d)
{
	if (d == 0)
	{
		std::cout << "STOP DIVISOR BY ZERO!";
	}
	else
	{
		denom = d;
	}
}

int Rational::getNumer()
{
	return numer;
}

int Rational::getDenom()
{
	return denom;
}

// WIP FORCED SOLUTION

void Rational::simplify()
{
	if (numer == 0)
	{
		numer = 0;
		denom = 1;
	}
	else if (numer == denom)
	{
		numer = 1;
		denom = 1;
	}
	else
	{
		factorPrime(2);
		factorPrime(3);
		factorPrime(5);
		factorPrime(7);
		factorPrime(11);
		factorPrime(13);
	}
	
}

void Rational::simplify(Rational r)
{
	if (r.getNumer() == 0)
	{
		r.setNumer(0);
		r.setDenom(1);
	}
	else if (r.getNumer() == r.getDenom())
	{
		r.setNumer(1);
		r.setDenom(1);
	}
	else
	{
		factorPrime(r, 2);
		factorPrime(r, 3);
		factorPrime(r, 5);
		factorPrime(r, 7);
		factorPrime(r, 11);
		factorPrime(r, 13);
	}

}

void Rational::factorPrime(unsigned short p)
{
	while ((numer % p == 0) && (denom % p == 0))
	{
		numer /= p;
		denom /= p;
	}
}

void Rational::factorPrime(Rational r, unsigned short p)
{
	while ((r.getNumer() % p == 0) && (r.getDenom() % p == 0))
	{
		r.setNumer(r.getNumer() / p);
		r.setDenom(r.getDenom() / p);
	}
}
