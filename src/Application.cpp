#include <iostream>

#include <util/Random.h>
#include <util/HashTest.h>
#include <HashMap.h>
#include <HashMapLP.h>
#include <HashMapDH.h>

// STL and STD includes
#include <string>
#include <unordered_map>
#include <functional>

struct Jedi
{
    Jedi() {}
    ~Jedi() = default;

    char name = 1;
    unsigned int padawanCount = 0;
    unsigned int saberColor = 0;
};

int main()
{
    srand(time(nullptr));
    HashTest<Jedi>();
}