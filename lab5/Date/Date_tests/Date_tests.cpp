//#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../DateProject/Date.h"

TEST_CASE("Create CDate object")
{
	WHEN("We create 3.1.1970")
	{
		CDate date(3, Month::JANUARY, 1970);

		THEN("We get correct data")
		{
			CHECK(date.GetTimestamp() == 2);
			CHECK(date.GetDay() == 3);
			CHECK(date.GetMonth() == Month::JANUARY);
			CHECK(date.GetYear() == 1970);
			CHECK(date.GetWeekDay() == WeekDay::SATURDAY);
		}
	}
	WHEN("We create 31.12.9999")
	{
		CDate date(31, Month::DECEMBER, 9999);

		THEN("We get correct data")
		{
			CHECK(date.GetTimestamp() == 2932896);
			CHECK(date.GetDay() == 31);
			CHECK(date.GetMonth() == Month::DECEMBER);
			CHECK(date.GetYear() == 9999);
			CHECK(date.GetWeekDay() == WeekDay::FRIDAY);
		}
	}
	WHEN("We create 29.02.1972 - leap eyar")
	{
		CDate date(29, Month::FEBRUARY, 1972);

		THEN("We get correct data")
		{
			CHECK(date.GetTimestamp() == 789);
			CHECK(date.GetDay() == 29);
			CHECK(date.GetMonth() == Month::FEBRUARY);
			CHECK(date.GetYear() == 1972);
			CHECK(date.GetWeekDay() == WeekDay::TUESDAY);
		}
	}
}
