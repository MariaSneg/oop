#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <Windows.h>
#include "dictionaryFunctions.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string data;
	bool isChanged = false;

	try
	{
		auto dictionaryFileName = ParseArgs(argc, argv);
		std::map<std::string, std::string> dictionary = ParseDictionary("input.txt");

		while (getline(std::cin, data))
		{
			if (data == "...")
			{
				if (isChanged)
				{
					std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << std::endl;
					std::string response;
					std::cin >> response;

					if (response != "y" && response != "Y")
					{
						std::cout << "Изменения не сохранены" << std::endl;
					}
					else
					{
						SaveChanges(dictionary, "input.txt");
					}
				}
				break;
			}

			std::string translateWord = TranslateWord(data, dictionary, isChanged);

			if (!translateWord.empty())
			{
				std::cout << translateWord << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}
	return 0;
}
