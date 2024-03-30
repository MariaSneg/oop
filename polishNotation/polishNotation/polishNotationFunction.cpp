#include "polishNotationFunction.h"
#include <vector>
#include <fstream>
#include <sstream> 
int PolishNotation(std::istream& input)
{
    std::vector<char> operations;
    std::vector<std::string> operands;
    char operation;
    std::string line;

    if (std::getline(input, line))
    {
        std::istringstream iss(line);
        char ch;

        while (iss >> ch)
        {
            if (ch == '*' || ch == '+')
            {
                operations.push_back(ch);
            }
            if (std::isdigit(ch))
            {
                operands.push_back(std::to_string(ch));
            }
            if (ch == '(')
            {
                operands.push_back(std::to_string(ch));
            }
            if (ch == ')')
            {
                operation = operations.back();
                if (operands.size() >= 2)
                {
                    int int1 = std::stoi(operands.back());
                    operands.pop_back();
                    int result = int1;
                    while (operands.back() != "(")
                    {
                        int int2 = std::stoi(operands.back());
                        operands.pop_back();
                        if (operation == '+')
                        {
                            result += int2;
                        }
                        else
                        {
                            result *= int2;
                        }
                    }
                    operands.push_back(std::to_string(result));
                    operands.pop_back();
                }
                operations.pop_back();
            }
        }

        return std::stoi(operands.back());
    }

    return 0; 
}
