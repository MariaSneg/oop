#include <iostream>
#include <sstream>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../PrimeNumbers/GeneratePrimeNumbersSet.h"

SCENARIO("Generate prime numbers")
{
	WHEN("We enter a number")
	{
		THEN("We get correct prime numbers set")
		{
			int upperBound = 50;

			std::set<int> correctSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

			std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

			CHECK(correctSet == primeNumbers);
		}
	}
	WHEN("We enter 100 000 000")
	{
		THEN("We get 5761455 prime numbers")
		{
			int upperBound = 100000000;

			std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

			CHECK(primeNumbers.size() == 5761455);
		}
	}
}
