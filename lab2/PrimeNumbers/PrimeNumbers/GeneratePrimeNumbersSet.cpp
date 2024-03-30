#include "GeneratePrimeNumbersSet.h"
#include <iostream>

std::set<int> GeneratePrimeNumbersSet(int const& upperBound)
{
    int count = upperBound + 1;
    std::vector<bool> sieve(count, true);

    std::set<int> primeNumbers;

    //оптимизировать 

    for (int i = 2; i <= upperBound; i++)
    {
        if (sieve[i])
        {
            primeNumbers.insert(i);
            if (i  < INT_MAX / i)
            {
                for (int j = i * i; j <= upperBound;)
                {
                    sieve[j] = false;
                    j += i;
                }
            }
        }
    }

    return primeNumbers;
}
