#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class CBody;

class CBodiesHandler
{
public:
	CBodiesHandler(std::istream& input, std::ostream& output);
	void HandleBody(std::string body);
	void PrintBodies() const;
	double MinMassInWater() const;
	double MaxMass() const;
private:
	std::vector<std::unique_ptr<CBody>> m_bodies;

	std::istream& m_input;
	std::ostream& m_output;
};