#include <iostream>
#include <sstream> 
#include "polishNotationFunction.h"

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::cout << PolishNotation(iss) << std::endl;
    }
}
