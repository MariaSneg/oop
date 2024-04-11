#include "RemoteControl.h"
#include "Car.h"
#include <sstream>

CRemoteControl::CRemoteControl(Car& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Info", bind(&CRemoteControl::Info, this, std::placeholders::_1) },
		{ "EngineOn", bind(&CRemoteControl::EngineOn, this, std::placeholders::_1) },
		{ "EngineOff", bind(&CRemoteControl::EngineOff, this, std::placeholders::_1) },
	    { "SetGear", bind(&CRemoteControl::SetGear, this, std::placeholders::_1) },
	    { "SetSpeed", bind(&CRemoteControl::SetSpeed, this, std::placeholders::_1) },
		})
{
}

bool CRemoteControl::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		if (!it->second(strm))
		{
			return false;
		}
		return true;
	}

	return false;
}

bool CRemoteControl::EngineOn(std::istream& args)
{
	m_car.TurnOnEngine();
	m_output << "Engine is turned on" << std::endl;
	return true;
}

bool CRemoteControl::EngineOff(std::istream& args)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine is turned off" << std::endl;
		return true;
	}
	m_output << "Engine can't be turned off. Reduce speed to 0 and shift gear to neutral" << std::endl;
	return false;
}

bool CRemoteControl::SetGear(std::istream& args)
{
	int gear;
	args >> gear;
	if (m_car.SetGear(gear))
	{
		m_output << "Gear changed to " << gear << std::endl;
		return true;
	}
	m_output << "Gear can't be changed" << std::endl;
	return false;
}

bool CRemoteControl::SetSpeed(std::istream& args)
{
	int speed;
	args >> speed;
	if (m_car.SetSpeed(speed))
	{
		m_output << "speed changed to " << speed << std::endl;
		return true;
	}
	m_output << "speed can't be changed" << std::endl;
	return false;
}

bool CRemoteControl::Info(std::istream& args)
{
	std::string info = (m_car.IsTurnedOn())
		? ("Engine is turn on\nGear is: " + std::to_string(m_car.GetGear()) + "\nSpeed is: "  + std::to_string(m_car.GetSpeed()) + "\n" + m_car.GetDirection() + "\n")
		: "Engine is turned off\n";

	m_output << info;

	return true;
}