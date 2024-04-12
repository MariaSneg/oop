#include <iostream>
#include <map>
#include <utility>

extern std::map<int, std::pair<int, int>> Gears;

enum class Direction {
	Forward, Backward, Standing
};

//сделать методы, не изменяющие состояние, константными

class Car
{
public:
	bool IsTurnedOn();
	//возвращать enum, преобразовывать при выводе
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
	//убрать m_direction
	Direction m_direction = Direction::Standing;
	int m_speed = 0;
	int m_gear = 0;
};