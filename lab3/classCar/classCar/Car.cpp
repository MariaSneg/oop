#include "Car.h"

const std::map<int, std::pair<int, int>> Gears
{
    { -1, std::make_pair(-20, 0)},
    { 0, std::make_pair(0, 0)},
    { 1, std::make_pair(0, 30)},
    { 2, std::make_pair(20, 50)},
    { 3, std::make_pair(30, 60)},
    { 4, std::make_pair(40, 90)},
    { 5, std::make_pair(50, 150)}
};

bool Car::IsTurnedOn() const
{
    return m_engineCondition;
}

std::string Car::GetDirection() const
{
    std::string direction;
    if (m_speed > 0)
    {
        direction = "Forward";
    }
    else if (m_speed < 0)
    {
        direction = "Backward";
    }
    else 
    {
        direction = "Standing";
    }
    return direction;
}

int Car::GetSpeed() const
{
    if (m_speed < 0)
    {
        return -m_speed;
    }
    return m_speed;
}

int Car::GetGear() const
{
    return m_gear;
}

bool Car::TurnOnEngine()
{
    if (m_engineCondition)
    {
        return true;
    }
    m_engineCondition = true;
    return true;
}

bool Car::TurnOffEngine()
{
    if (!m_engineCondition)
    {
        return true;
    }
    if (m_speed == 0 && m_gear == 0)
    {
        m_engineCondition = false;
        return true;
    }
    return false;
}

bool Car::SetGear(int gear)
{
    if (!m_engineCondition)
    {
        return false;
    }
    if (Gears.find(gear) == Gears.end())
    {
        return false;
    }
    if (gear == -1 && m_speed == 0)
    {
        m_gear = gear;
        return true;
    }
    else if (gear == 0)
    {
        m_gear = gear;
        return true;
    }
    else if (m_speed >= Gears.at(gear).first && m_speed <= Gears.at(gear).second && gear != -1) {
        m_gear = gear;
        return true;
    }
    
    return false;
}

bool Car::SetSpeed(int speed)
{
    if (speed < 0)
    {
        return false;
    }
    if (!m_engineCondition)
    {
        return false;
    }

    if (m_gear == -1 && -speed >= Gears.at(m_gear).first && -speed <= Gears.at(m_gear).second)
    {
        m_speed = -speed;
        return true;
    }
    else if (m_gear == 0)
    {
        if (m_speed < 0 && speed <= -m_speed)
        {
            m_speed = -speed;
            return true;
        }
        else if (speed <= m_speed)
        {
            m_speed = speed;
            return true;
        }
        //не использовать квадратные скобки
    }
    else if (speed >= Gears.at(m_gear).first && speed <= Gears.at(m_gear).second)
    {
        m_speed = speed;
        return true;
    }
    return false;
}