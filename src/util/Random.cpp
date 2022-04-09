#include <util/Random.h>

#include <cmath>
#include <random>

namespace util
{
    // from 0 to 18 446 744 073 709 551 615
    unsigned long long generateRandLong()
    {
        unsigned long long result = 0;
        size_t iters = rand() % 14 + 6;
        for (size_t i = 0; i < iters; i++)
            result += (rand() % 10) * pow(10, i);

        return result;
    }
}