#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <functional>
#include <array>

using FindStringCallback = std::function<void(float(&matrix)[3][3])>;

const int n = 3;
const int m = 3;

struct Args
{
	std::string inputFileName;
	std::string str;
};

//использовать std::array для хранения 
using Matrix3x3 = std::array<std::array<double, 3>, 3>;


void PrintMatrix(float (&matrix)[n][m])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << std::fixed << std::showpoint;
			std::cout << std::setprecision(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void ReadMatrix(std::istream& input, float(&matrix)[n][m]) 
{
	//
	if (input.eof())
	{
		throw std::runtime_error("File is empty\n");
	}
	std::string temp1, temp2, temp3;
	for (int i = 0; i < n; ++i)
	{
		// записывать сразу в элементы матрицы
		input >> temp1 >> temp2 >> temp3;
		matrix[i][0] = std::stof(temp1);
		matrix[i][1] = std::stof(temp2);
		matrix[i][2] = std::stof(temp3);
	}
}

void GetMinor(float(&minor)[n - 1][m - 1], const float(&matrix)[n][m], const int row, const int column)
{
	int difI, difJ;
	difI = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (i == row)
		{
			difI = 1;
		}
		difJ = 0;
		for (int j = 0; j < m - 1; ++j)
		{
			if (j == column)
			{
				difJ = 1;
			}
			minor[i][j] = matrix[i + difI][j + difJ];
		}
	}
}

float MinorDeterminate(const float(&minor)[n - 1][m - 1])
{
	float determinate = minor[0][0] * minor[1][1] - minor[1][0] * minor[0][1];
	return determinate;
}

float FindMinorDeterminate(const float(&matrix)[n][m], const int row, const int column)
{
	float minor[n - 1][m - 1];
	GetMinor(minor, matrix, row, column);

	return MinorDeterminate(minor);
}

void TransMatrix(float(&transMatrix)[n][m], const float(&matrix)[n][m])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ((i + j) % 2 == 1)
			{
				transMatrix[j][i] = - FindMinorDeterminate(matrix, i, j);
			}
			else
			{
				transMatrix[j][i] = FindMinorDeterminate(matrix, i, j);
			}
		}
	}
}

float Determinate(const float(&matrix)[n][m])
{
	float determinate = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == 1)
		{
			determinate -= matrix[0][i] * FindMinorDeterminate(matrix, 0, i);
		}
		else
		{
			determinate += matrix[0][i] * FindMinorDeterminate(matrix, 0, i);
		}
	}
	
	return determinate;
}

//изменить название
void IsMatrixInverted(
	std::istream& input,
	const FindStringCallback& callback = FindStringCallback())
{
	float matrix[n][m];
	ReadMatrix(input, matrix);

	float determinate = Determinate(matrix);

	if (determinate == 0)
	{
		throw std::runtime_error("Determinate = 0\n");
	}

	float transposedMatrix[n][m];
	TransMatrix(transposedMatrix, matrix);

	//функция не должна печатать трансп. матрицу
	//PrintMatrix(transposedMatrix);

	float invertedMatrix[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			invertedMatrix[i][j] = transposedMatrix[i][j] * (1 / determinate);
		}
	}

	if (callback)
	{
		callback(invertedMatrix);
	}

	return;
}

void MatrixInFile(
	const std::string& inputFileName,
	const FindStringCallback& callback = FindStringCallback())
{
	std::ifstream input(inputFileName);

	if (!input.is_open())
	{
		throw std::runtime_error("Failed to open " + inputFileName + " for reading\n");
	}

	IsMatrixInverted(input, PrintMatrix);

	if (!input.eof())
	{
		throw std::runtime_error("Failed to read data\n");
	}

}

std::string ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		throw std::runtime_error("Invalid arguments count\n Usage: invert.exe <file name>\n");
	}

	return argv[1];
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	try
	{
		std::string inputFileName = ParseArgs(argc, argv);
		//прочитать матрицу, инвертировать матрицу, напечатать матрицу - функции, вызываемые в main
		//
		MatrixInFile(inputFileName, PrintMatrix);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}