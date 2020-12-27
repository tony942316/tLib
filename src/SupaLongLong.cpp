#include "SupaLongLong.h"

#include <iostream>

SupaLongLong::SupaLongLong()
{
	num.reset();
}

void SupaLongLong::PrintNum()
{
	std::cout << num << '\n';
}

void SupaLongLong::AddNum(unsigned long long y)
{

}

void SupaLongLong::inc(int start)
{
	for (int i = start; i < num.size(); i++)
	{
		if (num[i] == 0)
		{
			num[i] = 1;
			break;
		}
		else
		{
			num[i] = 0;
		}
	}
}

void SupaLongLong::translate(unsigned long long y)
{
	std::bitset<64> newY;
	newY.reset();
	newY = y;
}