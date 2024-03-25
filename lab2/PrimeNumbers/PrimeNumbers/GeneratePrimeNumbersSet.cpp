#include "GeneratePrimeNumberSet.h"
#include <iostream>

std::set<int> CreateNumbersSet(int const& upperBound)
{
    std::set<int> numberSet;
    for (int i = 2; i <= upperBound; i++)
    {
        numberSet.insert(i);
    }

    return numberSet;
}

std::vector<bool> Sieve(int const& upperBound)
{
    std::vector<bool> sieve(upperBound + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i * i < upperBound; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= upperBound; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

std::set<int> GeneratePrimeNumberSet(int const& upperBound)
{
    std::vector<bool> sieve(upperBound + 1, true);

    std::set<int> primeNumbers;

    for (int i = 2; i * i <= upperBound; i++)
    {
        if (sieve[i])
        {
            primeNumbers.insert(i);
            for (int j = i * i; j <= upperBound; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return primeNumbers;
}
