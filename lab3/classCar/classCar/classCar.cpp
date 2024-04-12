#include <iostream>
#include "Car.h"
#include "Driver.h"

int main()
{
	{
		}
	Car car;
	CDriver driver(car, std::cin, std::cout);
	//убрать вывод Unknown command при неправильном исполнении команды
	//при движении задом на нейтрали заднюю передачу можно включить только при скорости 0
		
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!driver.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}