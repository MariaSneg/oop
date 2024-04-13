#include <iostream>
#include "Car.h"
#include "Driver.h"

int main()
{
	Car car;
	CDriver driver(car, std::cin, std::cout);
		
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		driver.HandleCommand();
	}
	return 0;
}