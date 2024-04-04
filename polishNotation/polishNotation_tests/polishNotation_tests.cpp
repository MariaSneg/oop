#include <iostream>
#include <sstream>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

#include "../polishNotation/polishNotationFunction.h"

SCENARIO("Counting expression in polish notation")
{
	WHEN("Expression has one argument")
	{
		THEN("Result is equal to this argument")
		{
			std::string line = "( + 2)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 2);
		}
	}
	WHEN("Expression has two arguments")
	{
		THEN("Result is sum of arguments")
		{
			std::string line = "( + 2 3)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 5);
		}
	}
	WHEN("Expression has two arguments")
	{
		THEN("Result is product of arguments")
		{
			std::string line = "( * 2 4)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 8);
		}
	}
	WHEN("Expression has some arguments")
	{
		THEN("Result is sum of arguments")
		{
			std::string line = "( + 2 3 4)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 9);
		}
	}
	WHEN("Expression has some arguments")
	{
		THEN("Result is product of arguments")
		{
			std::string line = "( * 2 3 4)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 24);
		}
	}
	WHEN("Sum of products")
	{
		THEN("Result is product of arguments")
		{
			std::string line = "(+ (* 2 3) (* 3 4))";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 18);
		}
	}
	WHEN("Product of sum")
	{
		THEN("Result is correct")
		{
			std::string line = "(* (+ 1 2) (+ 3 1))";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 12);
		}
	}
	WHEN("Expression with many arguments and operation")
	{
		THEN("Result is correct")
		{
			std::string line = "(+ 5 (* 2 3 2) (+ 5 (+ 2 5) (* 2 2) ))";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 33);
		}
	}
	WHEN("Expression with negative arguments")
	{
		THEN("Result is correct")
		{
			std::string line = "(+ -2 3)";
			std::istringstream iss(line);

			int result = PolishNotation(iss);

			CHECK(result == 1);
		}
	}
}