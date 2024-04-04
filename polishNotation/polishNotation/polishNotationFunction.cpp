#include "polishNotationFunction.h"
#include <vector>
#include <sstream> 

//назвать функцию по другому(подсчет выражени€)
//istream  
int PolishNotation(std::istringstream& iss)
{
    //std::steck вместо вектора
    std::vector<char> operations;
    std::vector<std::string> operands;
    //по возможности объ€вл€ть переменные ближе к месту их использовани€
    //разделить на подфункции
    char operation;
    std::string line;

    char ch;

    while (iss >> ch)
    {
        if (ch == '*' || ch == '+')
        {
            operations.push_back(ch);
        }
        if (std::isdigit(ch))
        {
            std::string str;
            str += ch;
            /*while (std::isdigit(ch))
            {
                str += ch;
                iss >> ch;
            }*/
            operands.push_back(str);
        }
        if (ch == '(')
        {
            operands.push_back(std::string(1, ch));
        }
        if (ch == '-')
        {
            char ch2;
            std::string str;
            iss >> ch2;
            str += ch;
            str += ch2;
            operands.push_back(str);
        }
        if (ch == ')')
        {
            operation = operations.back();

            if (!operands.empty() && operands.size() >= 2)
            {
                int int1 = std::stoi(operands.back());
                operands.pop_back();
                int result = int1;
                while (!operands.empty() && operands.back() != "(")
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
                if (!operands.empty())
                {
                    operands.pop_back();
                }

                operands.push_back(std::to_string(result));
            }
            operations.pop_back();
        }
    }

    return std::stoi(operands.back());
}


// (- 1) падает