#pragma once

#include <bitset>

#include "tLib.h"

// Will be 128 bit integer one day, one of those "Yeah I can do that iN No TiMe!" moments

class SupaLongLong
{
public:
	SupaLongLong();
	void PrintNum();
	void AddNum(unsigned long long y);
public:
	void operator+=(unsigned long long y)
	{
		if ((y % 2) != 0)
		{
			inc();
			y--;
		}
		inc(factorTwos(&y));
		for (int i = 0; i < y - 1; i++)
		{
			inc();
		}

	}
	unsigned short factorTwos(unsigned long long* num)
	{
		unsigned short count = 0;
		while (*num % 2 == 0)
		{
			*num = *num / 2;
			count++;
		}
		return count;
	}
	//private:
	void inc(int start = 0);
	void translate(unsigned long long y);
private:
	std::bitset<128> num;
};

