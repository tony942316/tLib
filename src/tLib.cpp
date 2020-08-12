#include "tLib.h"

#include <string>
#include <conio.h>
#include <windows.h>

enum cinStates
{
	GOOD,
	END,
	FAIL,
	BAD = 4
};

namespace t
{

	/********************************************************
	* Intended to be called one line before "return 0" in the main function &&
	* with "Automatic Close the Console" Off
	* "Tools -> Options -> Debugging -> General"
	*
	* Prints the state of cin and waits for any key press
	**********************************************************/

	void Complete()
	{
		std::cout << "\n\n";
		ioCheck();
		std::cout << "Code ran to completion! Press any key to close this window.\n";
		_getch();
	}

	// [Overload] Prints designated number of newline characters before displaying msg

	void Complete(unsigned int newLines)
	{
		for (unsigned int i = 0; i < newLines; i++)
		{
			std::cout << '\n';
		}
		ioCheck();
		std::cout << "Code ran to completion! Press any key to close this window.\n";
		_getch();
	}

	// [Overload] Toggle printing of the state of cin

	void Complete(bool io)
	{
		std::cout << "\n\n";
		if (io)
		{
			ioCheck();
		}
		std::cout << "Code ran to completion! Press any key to close this window.\n";
		_getch();
	}

	// [Overload] Performs both the previous overloads in one

	void Complete(unsigned int newLines, bool io)
	{
		for (unsigned int i = 0; i < newLines; i++)
		{
			std::cout << '\n';
		}
		if (io)
		{
			ioCheck();
		}
		std::cout << "Code ran to completion! Press any key to close this window.\n";
		_getch();
	}

	// Prints the state of cin in a readable format to the console
	short ioCheck()
	{
		std::string cinStates[5] = { "GOOD", "EOF", "FAIL", "UNKNOWN", "BAD" };
		if ((std::cin.rdstate() != GOOD) && (std::cin.rdstate() != END) && (std::cin.rdstate() != FAIL) && (std::cin.rdstate() != BAD))
		{
			std::cout << "[CIN STREAM STATE]: WARNING! UNEXPECTED STREAM STATE!!! VALUE IS: " << std::cin.rdstate() << '\n';
		}
		else
		{
			std::cout << "[CIN STREAM STATE]: " << cinStates[std::cin.rdstate()] << '\n';
		}
		return std::cin.rdstate();
	}

	// Prints all primitive data types with sizes and ranges (Visual Studio Implementation)

	void printPrimitiveInfo()
	{
		std::cout << "All primitive data types with sizes and ranges (Visual Studio Implementation)\n\n";
		std::cout << "[bool]----------------1 byte      true or false\n";
		std::cout << "[char]----------------1 byte,    -128 to 127\n";
		std::cout << "[unsigned char]-------1 byte,     0 to 255\n";
		std::cout << "[wchar_t]-------------2 bytes,    0 to 65,535\n";
		std::cout << "[short]---------------2 bytes,   -32,768 to 32,767\n";
		std::cout << "[unsigned short]------2 bytes,    0 to 65,535\n";
		std::cout << "[int]-----------------4 bytes,   -2,147,483,648 to 2,147,483,647\n";
		std::cout << "[unsigned int]--------4 bytes,    0 to 4,294,967,295\n";
		std::cout << "[long long]-----------8 bytes,   -9 Quintillion to 9 Quintillion (approx)\n";
		std::cout << "[unsigned long long]--8 bytes,    0 to 18 Quintillion (approx)\n";
		std::cout << "[float]---------------4 bytes,    3.4E+/-38 (approx)\n";
		std::cout << "[double]--------------8 bytes,    1.7E+/-308 (approx)\n";
	}

	// Prints low priority exception msg to console

	void printNote(std::string note)
	{
		printColor(COLORS::GREY, "[NOTE]: " + note);
	}

	// Prints priority exception msg to console

	void printWarning(std::string warning)
	{
		printColor(COLORS::YELLOW, "[WARNING]: " + warning);
	}

	// Prints high priority exception msg to console

	void printError(std::string error)
	{
		printColor(COLORS::RED, "[ERROR]: " + error);
	}

	void printColor(COLORS color, std::string word)
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);

		SetConsoleTextAttribute(hstdout, (WORD)color);
		std::cout << word;
		SetConsoleTextAttribute(hstdout, csbi.wAttributes);
		std::cout << '\n';
	}

	void printColor(COLORS color, std::string preLim, std::string word)
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);

		std::cout << preLim;
		SetConsoleTextAttribute(hstdout, (WORD)color);
		std::cout << word;
		SetConsoleTextAttribute(hstdout, csbi.wAttributes);
		std::cout << '\n';
	}

	void printColor(COLORS color, std::string preLim, std::string word, std::string post)
	{
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);

		std::cout << preLim;
		SetConsoleTextAttribute(hstdout, (WORD)color);
		std::cout << word;
		SetConsoleTextAttribute(hstdout, csbi.wAttributes);
		std::cout << post << '\n';
	}
}
