#include <iostream>

#include <util/Random.h>
#include <util/HashTest.h>
#include <HashMap.h>
#include <string>

// STL includes
#include <unordered_map>
#include <functional>

struct Jedi
{
    Jedi() {}
    ~Jedi() = default;

    // std::string name{};
    char c = 1;
    unsigned int padawanCount = 0;
    unsigned int saberColor = 0;
};

template<class T> bool HashTest();

int main()
{
    srand(time(nullptr));
    HashTest<Jedi>();
}