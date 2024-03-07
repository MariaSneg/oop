#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int n = 3;
const int m = 3;

struct Args
{
	std::string inputFileName;
	std::string str;
};

void PrintMatrix(float(&matrix)[n][m])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << std::setprecision(10) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool IsMatrixInverted(std::ifstream& input)
{
	float matrix[n][m];
	std::string temp1, temp2, temp3;
	for (int i = 0; i < n; ++i)
	{
		input >> temp1 >> temp2 >> temp3;
		matrix[i][0] = std::stof(temp1);
		matrix[i][1] = std::stof(temp2);
		matrix[i][2] = std::stof(temp3);
	}

	float d1 = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2];
	float d2 = matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[1][2] * matrix[2][1];
	float determinate = d1 - d2;

	std::cout << determinate << std::endl;

	if (determinate == 0)
	{
		return false;
	}

	float transMatrix[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			transMatrix[j][i] = matrix[i][j];
		}
	}

	float invertedMatrix[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			invertedMatrix[i][j] = transMatrix[i][j] * (1 / determinate);
		}
	}

	PrintMatrix(invertedMatrix);

	return true;
}

bool IsStringInFile(const std::string& inputFileName)
{
	std::ifstream input(inputFileName);

	if (!input.is_open())
	{
		std::cout << "Failed to open " << inputFileName << " for reading\n";
		return false;
	}

	if (!IsMatrixInverted(input))
	{
		return false;
	}

	
	return true;
}

std::string ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name>\n";
		return "";
	}

	return argv[1];
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	auto inputFileName = ParseArgs(argc, argv);
	if (inputFileName == "")
	{
		return 1;
	}
	if (!IsStringInFile(inputFileName))
	{
		return 1;
	}

	return 0;
}