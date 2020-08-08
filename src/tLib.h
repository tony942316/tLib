#pragma once
#include <iostream>
namespace t
{
	void Complete();
	void Complete(unsigned int newLines);
	void Complete(bool io);
	void Complete(unsigned int newLines, bool io);
	short ioCheck();
	void printPrimitiveInfo();

	// Prints array using template parameter deduction to determine size

	template<typename T, size_t S>
	void arrPrint(T(&arr)[S])
	{
		for (size_t i = 0; i < S; i++)
		{
			std::cout << "Index[" << i << "]: " << arr[i] << '\n';
		}
	}

	// Returns array size using template parameter deduction

	template<typename T, size_t S>
	size_t arrSize(T(&arr)[S])
	{
		return S;
	}


	void printNote(const char* note);
	void printWarning(const char* warning);
	void printError(const char* error);
}
