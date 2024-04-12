#include <iostream>
#include "Car.h"
#include "Driver.h"

int main()
{
	{
		}
	Car car;
	CDriver driver(car, std::cin, std::cout);
	//при движении задом на нейтрали заднюю передачу можно включить только при скорости 0
		
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		driver.HandleCommand();
	}
	return 0;
}