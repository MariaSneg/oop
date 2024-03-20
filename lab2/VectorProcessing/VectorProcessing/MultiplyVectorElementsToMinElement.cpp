#include "MultiplyVectorElementsToMinElement.h"
#include <iterator>
#include <fstream>

std::vector<double> MultiplyVectorElementsToMinElement(std::istream& input, std::ostream& output)
{
	std::vector<double> elements = ReadVector(input);

	if (elements.empty())
	{
		return elements;
	}

	double minElement = *std::min_element(elements.begin(), elements.end());

	std::cout << minElement << std::endl;

	for (int i = 0; i < elements.size(); i++)
	{
		elements[i] *= minElement;
	}

	copy(elements.begin(), elements.end(), std::ostream_iterator<double>(output, " "));

	return elements;
}

std::vector<double> ReadVector(std::istream& input)
{

	std::vector<double> elements;
	double element;
	while (input >> element)
	{
		elements.push_back(element);
	}

	return elements;
}