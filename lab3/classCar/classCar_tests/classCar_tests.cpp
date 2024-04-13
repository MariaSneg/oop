#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../classCar/Car.h"
#include "../classCar/Driver.h"

struct CarFixture
{
	Car car;
};

TEST_CASE_METHOD(CarFixture, "car is standing and has speed 0 and gear 0 by default")
{
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

		THEN("Engine is on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
}

TEST_CASE_METHOD(CarFixture, "Turn off engine")
{
	WHEN("Car is standing and has speed 0 and gear 0")
	{
		car.TurnOffEngine();

		THEN("Engine is turned off")
		{
			CHECK(!car.IsTurnedOn());
		}
	}
}

TEST_CASE_METHOD(CarFixture, "Change gear")
{
	WHEN("Engine is turned off")
	{
		car.SetGear(1);

		THEN("Gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
	WHEN("Car is standing and has speed 0 and gear 0, shift to gear 1")
	{
		car.TurnOnEngine();
		car.SetGear(1);

		THEN("Car has gear 1")
		{
			CHECK(car.GetGear() == 1);
		}
	}
	WHEN("Shift to gear -1")
	{
		car.TurnOnEngine();
		car.SetGear(-1);

		THEN("Car has gear -1")
		{
			CHECK(car.GetGear() == -1);
		}
	}
	WHEN("Shift to gear 3")
	{
		car.TurnOnEngine();
		car.SetGear(3);

		THEN("Gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
}

TEST_CASE_METHOD(CarFixture, "Change speed")
{
	WHEN("Engine is turned off")
	{
		car.SetSpeed(10);

		THEN("Speed 0")
		{
			CHECK(car.GetSpeed() == 0);
		}
	}
	WHEN("Car is standing and has speed 0 and gear 0, enter speed 25")
	{
		car.TurnOnEngine();
		car.SetSpeed(25);

		THEN("Speed 0")
		{
			CHECK(car.GetSpeed() == 0);
		}
	}
}

struct CarMovingForwardFixture : public CarFixture
{
	CarMovingForwardFixture()
	{
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(25);
	}
};

TEST_CASE_METHOD(CarMovingForwardFixture, "Car has speed and gear")
{
	CHECK(car.GetSpeed() == 25);
	CHECK(car.GetGear() == 1);
	CHECK(car.GetDirection() == "Forward");
}

TEST_CASE_METHOD(CarMovingForwardFixture, "Turn off engine of moving car")
{
	WHEN("Car is moving, engine can't be turned off")
	{

		car.TurnOffEngine();

		THEN("Engine is on")
		{
			CHECK(car.IsTurnedOn());
		}
	}
}

TEST_CASE_METHOD(CarMovingForwardFixture, "Change gear of moving car")
{
	WHEN("Car has speed 25, shift to gear 2")
	{
		car.SetGear(2);

		THEN("Car has gear 2")
		{
			CHECK(car.GetGear() == 2);
		}
	}
	WHEN("Shift to gear 0")
	{
		car.SetGear(0);

		THEN("Car has gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
	WHEN("Shift to gear -1")
	{
		car.SetGear(-1);

		THEN("Gear 1")
		{
			CHECK(car.GetGear() == 1);
		}
	}
	WHEN("Shift to gear 3")
	{
		car.SetGear(3);

		THEN("Gear 1")
		{
			CHECK(car.GetGear() == 1);
		}
	}
}

TEST_CASE_METHOD(CarMovingForwardFixture, "Change speed of moving car")
{
	WHEN("Car has gear 1, enter speed 20")
	{
		car.SetSpeed(20);

		THEN("Car has speed 20")
		{
			CHECK(car.GetSpeed() == 20);
		}
	}
	WHEN("Car has gear 1, enter speed 30")
	{
		car.SetSpeed(30);

		THEN("Car has speed 30")
		{
			CHECK(car.GetSpeed() == 30);
		}
	}
	WHEN("Car has gear 1, enter speed 40")
	{
		car.SetSpeed(40);

		THEN("Speed 25")
		{
			CHECK(car.GetSpeed() == 25);
		}
	}
}

struct CarMovingBackwardFixture : public CarFixture
{
	CarMovingBackwardFixture()
	{
		car.TurnOnEngine();
		car.SetGear(-1);
		car.SetSpeed(15);
	}
};

TEST_CASE_METHOD(CarMovingBackwardFixture, "Change gear of moving backward car")
{
	WHEN("Car has speed 15, shift to gear 1")
	{
		car.SetGear(1);

		THEN("Car has gear -1")
		{
			CHECK(car.GetGear() == -1);
		}
	}
	WHEN("Shift to gear 0")
	{
		car.SetGear(0);

		THEN("Car has gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
	WHEN("Car has speed 0, shift to gear 1")
	{
		car.SetSpeed(0);
		car.SetGear(1);

		THEN("Car has gear 1")
		{
			CHECK(car.GetGear() == 1);
		}
	}
	WHEN("Car has speed 0, shift to gear 2")
	{
		car.SetSpeed(0);
		car.SetGear(2);

		THEN("Car has gear -1")
		{
			CHECK(car.GetGear() == -1);
		}
	}
	WHEN("Car has speed 15, shift to gear 0, then to 1")
	{
		car.SetGear(0);
		car.SetGear(1);

		THEN("Car has gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
	WHEN("Car has speed 15, shift to gear 0, then to -1")
	{
		car.SetGear(0);
		car.SetGear(-1);

		THEN("Car has gear 0")
		{
			CHECK(car.GetGear() == 0);
		}
	}
}

TEST_CASE_METHOD(CarMovingBackwardFixture, "Change speed of moving backward car")
{
	WHEN("Car has gear -1, enter speed 20")
	{
		car.SetSpeed(20);

		THEN("Car has speed 20")
		{
			CHECK(car.GetSpeed() == 20);
		}
	}
	WHEN("Car has gear -1, enter speed 30")
	{
		car.SetSpeed(30);

		THEN("Car has speed 15")
		{
			CHECK(car.GetSpeed() == 15);
		}
	}
}