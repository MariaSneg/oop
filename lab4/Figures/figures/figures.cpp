#include "sphere.h"
#include "parallelepiped.h"
#include "cone.h"
#include "cylinder.h"
#include <vector>
#include <memory>
#include <iostream>

void AddSphere(std::vector<std::unique_ptr<CBody>>& bodies)
{
	auto s = std::make_unique<CSphere>(1000.0, 1.0);
	bodies.push_back(std::move(s));
}

void AddParallelepiped(std::vector<std::unique_ptr<CBody>>& bodies)
{
	auto s = std::make_unique<CParallelepiped>(100.0, 10.0, 10.0, 10.0);
	bodies.push_back(std::move(s));
}

void AddCone(std::vector<std::unique_ptr<CBody>>& bodies)
{
	auto s = std::make_unique<CCone>(100.0, 100.0, 10.0);
	bodies.push_back(std::move(s));
}

void AddCylinder(std::vector<std::unique_ptr<CBody>>& bodies)
{
	auto s = std::make_unique<CCylinder>(100.0, 100.0, 10.0);
	bodies.push_back(std::move(s));
}


int main()
{
	std::vector<std::unique_ptr<CBody>> bodies;
	AddSphere(bodies);
	AddParallelepiped(bodies);
	AddCone(bodies);
	AddCylinder(bodies);
	std::cout << bodies[0]->ToString() << std::endl;
	std::cout << bodies[1]->ToString() << std::endl;
	std::cout << bodies[2]->ToString() << std::endl;
	std::cout << bodies[3]->ToString() << std::endl;
	return 0;
}