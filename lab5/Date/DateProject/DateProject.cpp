#include "Date.h"
#include <iostream>


int main()
{
    CDate date1(31, Month::DECEMBER, 9999);
    CDate date2(29, Month::FEBRUARY, 1972);
    std::cout << date1.GetTimestamp() << std::endl;
    std::cout << date2.GetTimestamp() << std::endl;
    std::cout << date1.GetYear() << " " << static_cast<int>(date1.GetMonth()) << " " << date1.GetDay() << " " << static_cast<int>(date1.GetWeekDay()) << std::endl;
    std::cout << date2.GetYear() << " " << static_cast<int>(date2.GetMonth()) << " " << date2.GetDay() << " " << static_cast<int>(date2.GetWeekDay()) << std::endl;
}

