#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

struct Args {
	string inputFileName;
	string str;
};

void PrintIndexLine(int indexLine) {
	cout << indexLine << endl;
}

bool FindStringInFile(ifstream& input, string str) {
	string line;
	bool found = false;

	for (int indexLine = 1; getline(input, line); ++indexLine) {
		cout << line << endl;

		auto position = line.find(str);

		if (position != string::npos) {
			found = true;
			PrintIndexLine(indexLine);
		}
	}
	return found;
}

optional<Args> ParseArgs(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return nullopt;
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

	ifstream input(args->inputFileName);

	if (!input.is_open())
	{
		cout << "Failed to open " << args->inputFileName << " for reading\n";
		return 1;
	}

	if (!FindStringInFile(input, args->str))
	{
		cout << "Text not find\n";
		return 1;
	}

	return 0;
}