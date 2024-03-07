#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <functional>

using FindStringCallback = std::function<void(int indexLine)>;

struct Args 
{
	std::string inputFileName;
	std::string str;
};

void stringInStream(
	const std::string& str, 
	std::istream& input,
	const FindStringCallback& callback = FindStringCallback())
{
	std::string line;
	bool found = false;

	//lineIndex
	for (int lineIndex = 1; getline(input, line); ++lineIndex)
	{
		auto position = line.find(str);

		if (position != std::string::npos) 
		{
			found = true;
			if (callback)
			{
				callback(lineIndex);
			}
		}
	}
	if (!found)
	{
		throw std::runtime_error("Text not find\n");
	}
}

void PrintIndexLine(int lineIndex)
{
	std::cout << lineIndex << std::endl;
}

void stringInFile(
	const std::string& str, 
	const std::string& inputFileName,
	const FindStringCallback& callback = FindStringCallback())
{
	std::ifstream input(inputFileName);

	if (!input.is_open())
	{
		//использовать исключения для сигнала об ошибке вместо вывода
		throw std::runtime_error("Failed to open " + inputFileName + " for reading\n");
	}

	if (str.empty()) 
	{
		throw std::runtime_error("Search is empty\n");
	}

	stringInStream(str, input, callback);

	if (!input.eof())
	{
		throw std::runtime_error("Failed to read data\n");
	}
}

std::optional<Args> ParseArgs(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		throw std::runtime_error("Invalid arguments count\n Usage: findtext.exe <file name> \"text to search\"\n");
	}
	Args args;
	args.inputFileName = argv[1];
	args.str = argv[2];
	return args;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	try
	{
		auto args = ParseArgs(argc, argv);
		stringInFile(args->str, args->inputFileName, PrintIndexLine);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}