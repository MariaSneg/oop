#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../VectorProcessing/MultiplyVectorElementsToMinElement.h"

SCENARIO("Read Vector")
{
	WHEN("Input stream is empty")
	{
		std::istringstream input("");
		THEN("Vector is empty")
		{
			std::vector<double> elements = ReadVector(input);
			CHECK(elements.empty());
		}
	}
	
	WHEN("Input stream contains some elements")
	{
		std::istringstream input("3.5 4 5 6 1.6 2 3.6 1.111 ");
		THEN("Vector contains some elements")
		{
			std::vector<double> elements = ReadVector(input);
			CHECK(elements.size() == 8);
		}
	}
}

SCENARIO("Multiply vector elements to min element")
{
	std::ostringstream output;
	WHEN("Input stream is empty")
	{
		std::istringstream input("");
		THEN("Returned vector is also empty")
		{
			std::vector<double> elements = MultiplyVectorElementsToMinElement(input, output);
			CHECK(elements.empty());
		}
	}

	WHEN("Input stream contains some elements")
	{
		std::istringstream input("3.5 4 5 6 1.6 2 3.6 1.11");
		THEN("Output contains multiplued vector")
		{
			std::vector<double> elements = MultiplyVectorElementsToMinElement(input, output);
			CHECK(output.str() == "3.885 4.44 5.55 6.66 1.776 2.22 3.996 1.2321 ");
		}
	}
}