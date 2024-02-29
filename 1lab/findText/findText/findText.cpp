#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args 
{
	std::string inputFileName;
	std::string str;
};

bool IsStringInStream(const std::string& str, std::ifstream& input) 
{
	std::string line;
	bool found = false;

	for (int indexLine = 1; getline(input, line); ++indexLine) 
	{

		auto position = line.find(str);

		if (position != std::string::npos) 
		{
			found = true;
			std::cout << indexLine << std::endl;
		}
	}
	return found;
}

bool IsStringInFile(const std::string& str, const std::string& inputFileName)
{
	std::ifstream input(inputFileName);

	if (!input.is_open())
	{
		std::cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	if (!IsStringInStream(str, input))
	{
		std::cout << "Text not find\n";
		return false;
	}
	return true;
}

std::optional<Args> ParseArgs(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
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
	if (!IsStringInFile(args->str, args->inputFileName))
	{
		return 1;
	}

	return 0;
}