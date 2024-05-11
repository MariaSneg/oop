#include "sphere.h"
#include "parallelepiped.h"
#include "cone.h"
#include "cylinder.h"
#include "compound.h"
#include "bodiesHandler.h"
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Enter bodies. To exit enter \"...\"" << std::endl;
	
	CBodiesHandler handler(std::cin, std::cout);
	std::string body;
	while (std::cin >> body)
	{
		if (body == "...")
		{
			break;
		}
		handler.HandleBody(body);
        
        std::cout << "Next:" << std::endl;
	}

	handler.PrintBodies();

    std::cout << "Min mass in water:" << std::setprecision(10) << handler.MinMassInWater() << std::endl
        << "Max mass:" << handler.MaxMass() << std::endl;
	return 0;
}