#include <iostream>
#include <map>
#include <utility>

extern std::map<int, std::pair<int, int>> Gears;

enum class Direction {
	Forward, Backward, Standing
};

class Car
{
public:
	bool IsTurnedOn();
	std::string GetDirection();
	int GetSpeed();
	int GetGear();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool SetDirection();
private:
	bool m_engineCondition = false;
	Direction m_direction = Direction::Standing;
	int m_speed = 0;
	int m_gear = 0;
};