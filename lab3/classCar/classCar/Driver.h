#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <map>

class Car;

class CDriver
{
public:
	CDriver(Car& car, std::istream& input, std::ostream& output);
	bool HandleCommand() const;
private:
	bool Info(std::istream& args)  const;
	bool EngineOn(std::istream& args)  const;
	bool EngineOff(std::istream& args)  const;
	bool SetGear(std::istream& args)  const;
	bool SetSpeed(std::istream& args)  const;
private:
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;

	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};