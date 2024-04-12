#include <iostream>
#include <map>
#include <utility>

extern std::map<int, std::pair<int, int>> Gears;

//сделать методы, не изменяющие состояние, константными

class Car
{
public:
	const bool IsTurnedOn();
	const std::string GetDirection();
	const int GetSpeed();
	const int GetGear();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool m_engineCondition = false;
	int m_speed = 0;
	int m_gear = 0;
};