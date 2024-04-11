#include "Car.h"

std::map<int, std::pair<int, int>> Gears
{
    { -1, std::make_pair(-20, 0)},
    { 0, std::make_pair(0, 0) },
    { 1, std::make_pair(0, 30) },
    { 2, std::make_pair(20, 50) },
    { 3, std::make_pair(30, 60) },
    { 4, std::make_pair(40, 90) },
    { 5, std::make_pair(50, 150) }
};

bool Car::IsTurnedOn()
{
    return m_engineCondition;
}

std::string Car::GetDirection()
{
    std::string direction;
    if (m_direction == Direction::Forward)
    {
        direction = "Forward";
    }
    else if (m_direction == Direction::Backward)
    {
        direction = "Backward";
    }
    else if (m_direction == Direction::Standing)
    {
        direction = "Standing";
    }
    return direction;
}

int Car::GetSpeed()
{
    return m_speed;
}

int Car::GetGear()
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
    if (Gears.find(gear) != Gears.end())
    {
        if (gear == -1)
        {
            if (m_speed == 0)
            {
                m_gear = gear;
                return true;
            }
            return false;
        }
        if (m_gear == -1)
        {
            if (m_speed == 0)
            {
                m_gear = gear;
                return true;
            }
            return false;
        }
        if (m_speed >= Gears[gear].first && m_speed <= Gears[gear].second) {
            m_gear = gear;
            return true;
        }
    }
    
    return false;
}

bool Car::SetSpeed(int speed)
{
    if (m_gear == -1)
    {
        if (-speed >= Gears[m_gear].first && -speed <= Gears[m_gear].second)
        {
            m_speed = -speed;
            return true;
        }
    }
    else if (m_gear == 0)
    {
        if (speed <= m_speed)
        {
            m_speed = -speed;
            return true;
        }
    }
    else if (speed >= Gears[m_gear].first && speed <= Gears[m_gear].second)
    {
        m_speed = speed;
        return true;
    }
    return false;
}

bool Car::SetDirection()
{
    if (m_speed == 0)
    {
        m_direction = Direction::Standing;
        return true;
    }
    if (m_gear == -1)
    {
        m_direction = Direction::Backward;
        return true;
    }
    else 
    {
        m_direction = Direction::Forward;
        return true;
    }
}