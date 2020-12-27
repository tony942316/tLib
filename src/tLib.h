#pragma once
#include <iostream>

// Library of function for my personal use

// t for tony :D
namespace t
{
	enum struct COLORS
	{
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		PURPLE,
		YELLOW,
		WHITE,
		GREY
	};

	// Declarations

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


	void printNote(std::string note);
	void printWarning(std::string warning);
	void printError(std::string error);
	void printColor(COLORS color, std::string word);
	void printColor(COLORS color, std::string preLim, std::string word);
	void printColor(COLORS color, std::string preLim, std::string word, std::string post);

	unsigned long long expon(unsigned int x, unsigned int y);
}
