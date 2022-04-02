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

    std::string name{};
    unsigned int padawanCount = 0;
    unsigned int saberColor = 0;
};

int main()
{
    srand(time(nullptr));
    // srand(0);
    HashTest<Jedi>();
    // std::cout << HashMapDH<Jedi>::getNearestPrime(13) << std::endl;
    // HashMapDH<Jedi> map;
    // for (int i = 0; i < 100000; i++)
    // {
    //     map.Insert(Random::generateRandLong(), Jedi());
    //     std::cout << "D" << std::endl;
    // }

    // std::cout << map.Size() << std::endl;
}