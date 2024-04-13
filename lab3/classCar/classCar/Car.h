#include <iostream>
#include <map>
#include <utility>

class Car
{
public:
	bool IsTurnedOn() const;
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool m_engineCondition = false;
	int m_speed = 0;
	int m_gear = 0;
};