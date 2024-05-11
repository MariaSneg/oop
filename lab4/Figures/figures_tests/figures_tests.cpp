#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

#include "../figures/bodiesHandler.h"
#include "../figures/body.h"
#include "../figures/compound.h"
#include "../figures/cone.h"
#include "../figures/cylinder.h"
#include "../figures/parallelepiped.h"
#include "../figures/sphere.h"

TEST_CASE("Create sphere")
{
	WHEN("We enter density and radius")
	{
		//std::istringstream input("1200\n12\n"); 
		//std::ostringstream output;
		CSphere sphere(std::cin, std::cout, 1200, 12);

		THEN("We get correct density, radius, volume and mass")
		{
			CHECK(sphere.GetDensity() == 1200.0);
			CHECK(sphere.GetRadius() == 12.0);
			CHECK(sphere.GetVolume() == (pow(12.0, 3) * M_PI) * 4.0 / 3.0);
			CHECK(sphere.GetMass() == sphere.GetVolume() * 1200.0);
		}
	}
}

TEST_CASE("Create parallelepiped")
{
	WHEN("We enter density, weight, height and depth")
	{
		CParallelepiped parallelepiped(std::cin, std::cout, 1200, 12, 12, 12);

		THEN("We get correct density, weight, height, depth, volume and mass")
		{
			CHECK(parallelepiped.GetDensity() == 1200.0);
			CHECK(parallelepiped.GetWidth() == 12.0);
			CHECK(parallelepiped.GetHeight() == 12.0);
			CHECK(parallelepiped.GetDepth() == 12.0);
			CHECK(parallelepiped.GetVolume() == 12.0 * 12.0 * 12.0);
			CHECK(parallelepiped.GetMass() == parallelepiped.GetVolume() * 1200.0);
		}
	}
}

TEST_CASE("Create cone")
{
	WHEN("We enter density, height and base radius")
	{
		CCone cone(std::cin, std::cout, 1200, 12, 12);

		THEN("We get correct density, height, base radius, volume and mass")
		{
			CHECK(cone.GetDensity() == 1200.0);
			CHECK(cone.GetHeight() == 12.0);
			CHECK(cone.GetBaseRadius() == 12.0);
			CHECK(cone.GetVolume() == (pow(12, 2) * M_PI) * 12 / 3.0);
			CHECK(cone.GetMass() == cone.GetVolume() * 1200.0);
		}
	}
}

TEST_CASE("Create cylinder")
{
	WHEN("We enter density, height and base radius")
	{
		CCylinder cylinder(std::cin, std::cout, 1200, 12, 12);

		THEN("We get correct density, height, base radius, volume and mass")
		{
			CHECK(cylinder.GetDensity() == 1200.0);
			CHECK(cylinder.GetHeight() == 12.0);
			CHECK(cylinder.GetBaseRadius() == 12.0);
			CHECK(cylinder.GetVolume() == (pow(12, 2) * M_PI) * 12 );
			CHECK(cylinder.GetMass() == cylinder.GetVolume() * 1200.0);
		}
	}
}

//TEST_CASE("Create compound")
//{
//	WHEN("We enter child body")
//	{
//		CCompound compound(std::cin, std::cout);
//		CSphere sphere(std::cin, std::cout, 1200, 12);
//		compound.AddChildBody(sphere);
//
//		THEN("We get correct density, height, base radius, volume and mass")
//		{
//			CHECK(cylinder.GetDensity() == 1200.0);
//			CHECK(cylinder.GetHeight() == 12.0);
//			CHECK(cylinder.GetBaseRadius() == 12.0);
//			CHECK(cylinder.GetVolume() == (pow(12, 2) * M_PI) * 12);
//			CHECK(cylinder.GetMass() == cylinder.GetVolume() * 1200.0);
//		}
//	}
//}