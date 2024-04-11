#include <iostream>
#include <sstream>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../classCar/Car.h"
#include "../classCar/RemoteControl.h"

struct CarFixture
{
	Car car;
};

TEST_CASE_METHOD(CarFixture, "car is standing and has speed 0 and gear 0 by default")
{
	// Внутри этого тест-кейса мне доступны переменные из структуры StudentFixture
	CHECK(car.GetDirection() == "Standing");
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetGear() == 0);
}

TEST_CASE_METHOD(CarFixture, "Engine can be turned on")
{
	WHEN("Turn on engine")
	{
		car.TurnOnEngine();

		THEN("Engine is turned on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
	WHEN("Engine is already on")
	{
		car.TurnOnEngine();

		THEN("Engine stays on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
}

TEST_CASE_METHOD(CarFixture, "Engine can be turned off")
{
	WHEN("Turn off engine")
	{
		car.TurnOnEngine();

		THEN("Engine is turned on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
	WHEN("Engine is already on")
	{
		car.TurnOnEngine();

		THEN("Engine stays on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
}

}