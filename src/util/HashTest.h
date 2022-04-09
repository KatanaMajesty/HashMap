#pragma once

#include <util/Random.h>
#include <HashMap.h>
#include <HashMapLP.h>
#include <HashMapDH.h>

// STL includes
#include <unordered_map>

template<class T> bool HashTest()
{
    const int iters = 500'000'0;
    const int keysAmount = iters * 1;
    // generate random keys:
    long long* keys = new long long[keysAmount];
    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];
    for (int i = 0; i < keysAmount; i++)
    {
        keys[i] = util::generateRandLong();
    }
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = keys[util::generateRandLong() % keysAmount];
        keysToErase[i] = keys[util::generateRandLong() % keysAmount];
        keysToFind[i] = keys[util::generateRandLong() % keysAmount];
    }
    // test my HashTable:
    HashMapDH<T> hashTable;
    clock_t myStart = clock();
    for (int i = 0; i < iters; i++)
    {
    // std::cout << "Yes!" << std::endl;
        hashTable.Insert(keysToInsert[i], T());
    }

    int myInsertSize = hashTable.Size();
    // std::cout << "\n\n\nDone Insert!\n\n" << std::endl;
    for (int i = 0; i < iters; i++)
    {
        hashTable.Erase(keysToErase[i]);
    }
    // std::cout << "\n\n\nDone Erase!\n\n" << std::endl;
    int myEraseSize = hashTable.Size();
    int myFoundAmount = 0;
    // hashTable.print();
    for (int i = 0; i < iters; i++)
    {
        if (hashTable.Find(keysToFind[i]) != NULL)
        {
            myFoundAmount++;
        }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
    // test STL hash table:
    std::unordered_map<unsigned long long, T> unorderedMap;
    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({keysToInsert[i], T()}); 
    }
    int stlInsertSize = unorderedMap.size();
    std::cout << "STL" << std::endl;
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    int stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    // for (auto& pair : unorderedMap)
        // pair.second.print();

    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;
    std::cout << "My HashTable:" << std::endl ;
    std::cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize <<
    ", found amount: " << myFoundAmount << std::endl ;
    std::cout << "STL unordered_map:" << std::endl ;
    std::cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize
    << ", found amount: " << stlFoundAmount << std::endl  << std::endl ;
    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;
    if (myInsertSize == stlInsertSize 
        && myEraseSize == stlEraseSize 
        && myFoundAmount == stlFoundAmount)
    {
        std::cout << "The lab is completed" << std::endl ;
        return true;
    }
    std::cerr << ":(" << std::endl ;
    return false;
}