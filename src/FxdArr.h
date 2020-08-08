#pragma once
#include "tLib.h"

#include <stdarg.h>
#include <type_traits>
#include <windows.h>

//

template<typename T, unsigned long long S> 
struct FxdArr
{

// Constructors
public:

	// [DEFAULT] Set elements of the array to NULL

	FxdArr()
	{
		flush();
	}

	// Variadic constructor allows "array like" initialization

	template <typename V, typename... Vs>
	FxdArr(V first, Vs... rest)
	{
		flush(); // Set elements to "empty state"

		V tempArr[] = { first, rest... }; // Colect init values
		size_t tempArrSize = t::arrSize(tempArr); // Determine number of values in init

		// Check for too many values [WARNING]
		if (tempArrSize > S)
		{
			t::printWarning("To many arguments! Extra arguments removed!");
			tempArrSize = S;
		}

		// Check for too few values [NOTE]
		else if (tempArrSize < S)
		{
			t::printNote("Less arguments than size! Remaining space flushed!");
		}
		
		// Init array with provided init values
		for (size_t i = 0; i < tempArrSize; i++)
		{
			arr[i] = tempArr[i];
		}
	}

// private functions
private:

	// Sets every element of the array to the given value

	void populate(T thing)
	{
		for (size_t i = 0; i < S; i++)
		{
			arr[i] = thing;
		}
	}

	// Sets all values of the array to 0, 0.0, "", or ' ' based on type

	template <typename U>
	void flush()
	{			
		populate(0);
	}

	template<>
	void flush<std::string>()
	{
		populate("");
	}

	template<>
	void flush<char>()
	{
		populate(' ');
	}

	template<>
	void flush<unsigned char>()
	{
		populate(' ');
	}

	template<>
	void flush<float>()
	{
		populate(0.0f);
	}

	template<>
	void flush<double>()
	{
		populate(0.0);
	}

	template<>
	void flush<long double>()
	{
		populate(0.0L);
	}

// operator overloads
public:

	// Allow "array like" index operations

	T& operator[](short index)
	{
		if (index < 0)
		{
			t::printError("Access violation! Given index negative! Overwriting first element!");
			return arr[0];
		}
		else if (index > (S - 1))
		{
			t::printError("Access violation! Given index larger than array! Overwriting last element!");
			return arr[S - 1];
		}
		else
		{
			return arr[index];
		}
	}
	const T& operator[](short index) const
	{
		if (index < 0)
		{
			t::printError("Access violation! Given index negative! Overwriting first element!");
			return arr[0];
		}
		else if (index > (S - 1))
		{
			t::printError("Access violation! Given index larger than array! Overwriting last element!");
			return arr[S - 1];
		}
		else
		{
			return arr[index];
		}
	}



	void operator=(T otherArr[])
	{
		for (size_t i = 0; i < S; i++)
		{
			arr[i] = otherArr[i];
		}
	}

// public functions
public:

	// User level function for ease of use, clears the array

	void flush()
	{
		flush<T>();
	}

	// Prints all elements of the array to the console

	void print() const
	{
		for (size_t i = 0; i < S; i++)
		{
			std::cout << "Index[" << i << "]: " << arr[i] << '\n';
		}
		std::cout << '\n';
	}

	// Returns the size of the array

	constexpr size_t getSize() const
	{
		return S;
	}

// private variables
private:
	T arr[S];
};