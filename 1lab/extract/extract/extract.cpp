#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

struct Args {
	char* inputFileName;
	char* outputFileName;
};

void CopyStreams(ifstream& input, ofstream& output) {
	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			cout << "Failed to save data on disk\n";
			break;
		}
	}
}

optional<Args> ParseArgs(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

int main(int argc, char* argv[])
{
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

	ofstream output(args->outputFileName);
	if (!output.is_open())
	{
		cout << "Failed to open " << args->outputFileName << " for writing\n";
		return 1;
	}

	CopyStreams(input, output);

	if (!output.flush()) 
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

	return 0;
}