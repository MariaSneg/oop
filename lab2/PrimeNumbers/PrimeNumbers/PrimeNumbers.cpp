#include <iostream>
#include <chrono>
#include "GeneratePrimeNumberSet.h"

int main()
{
    int upperBound;
    std::cin >> upperBound;

    auto startTime = std::chrono::steady_clock::now();

    std::set<int> primeNumbers = GeneratePrimeNumberSet(upperBound);

    for (int i : primeNumbers)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    auto endTime = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << "ms" << std::endl;
}
