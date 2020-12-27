#pragma once

#include <iostream>

// NON-FUNCTIONAL

class Matrix
{
public:
	Matrix();
public:
	friend std::ostream& operator<<(std::ostream& os, Matrix r);
public:
	void rowEch();
	int* getArr();
private:
	unsigned short rows = 2;
	unsigned short cols = 2;
	int arr[16] = { 0, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0, 0 };
};

