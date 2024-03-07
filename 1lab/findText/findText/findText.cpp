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

bool IsStringInStream(
	const std::string& str, 
	std::istream& input,
	const FindStringCallback& callback = FindStringCallback())
{
	std::string line;
	bool found = false;

	//lineIndex
	for (int indexLine = 1; getline(input, line); ++indexLine) 
	{
		auto position = line.find(str);

		if (position != std::string::npos) 
		{
			found = true;
			if (callback)
			{
				callback(indexLine);
			}
		}
	}
	//проверить после чтения файла проверить, в каком состоянии input (eof)
	return found;
}

void PrintIndexLine(int indexLine) 
{
	std::cout << indexLine << std::endl;
}

bool IsStringInFile(
	const std::string& str, 
	const std::string& inputFileName,
	const FindStringCallback& callback = FindStringCallback())
{
	std::ifstream input(inputFileName);

	if (!input.is_open())
	{
		//использовать исключения для сигнала об ошибке вместо вывода
		std::cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	if (str.empty()) 
	{
		std::cout << "Search is empty\n";
		return false;
	}

	if (!IsStringInStream(str, input, callback))
	{
		std::cout << "Text not find\n";
		return false;
	}

	if (!input.eof())
	{
		std::cout << "File is unread\n";
		return false;
	}
	return true;
}

std::optional<Args> ParseArgs(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name> \"text to search\"\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.str = argv[2];
	return args;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	if (!IsStringInFile(args->str, args->inputFileName, PrintIndexLine))
	{
		return 1;
	}

	return 0;
}