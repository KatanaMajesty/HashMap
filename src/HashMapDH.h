#pragma once

#include <cmath>
#include <HashMapLP.h> // Temporary!

// Double Hashing
template<class T> class HashMapDH
{
private:
    struct Node
    {
        // 0 - empty
        // 1 - contains data
        // 2 - was once removed
        State state {EMPTY};
        unsigned long long key;
        T value;
    };
private:
    Node* m_Buckets;
    size_t m_Size;
    size_t m_Capacity;
    float m_LoadFactor;
    float m_LoadCapacity;
private:
    size_t h1(unsigned long long key) const noexcept
    {
        return ((7 * key - 13) % 234755096012779);
    }
    size_t h2(unsigned long long key) const noexcept
    {
        return ((136703551 * key) % 136703551);
    }

    size_t getNearestPrime(size_t number) const
    {
        for (size_t i = number + 1; true; i++)
        {
            bool isPrime = true;
            for (size_t j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                return i;
        }

        throw std::runtime_error("Couldn't find nearest prime");
    }
    
    void reallocate(float multiplier)
    {
        size_t capacityPrev = m_Capacity;
        m_Capacity = getNearestPrime(capacityPrev * multiplier);

        Node* arrayPrev = m_Buckets;
        m_Buckets = new Node[m_Capacity];

        for (size_t i = 0; i < capacityPrev; i++)
        {
            Node& nodePrev = arrayPrev[i];
            if (nodePrev.state == OCCUPIED)
            {
                const size_t hash = h1(nodePrev.key);
                size_t index = h1(nodePrev.key) % m_Capacity;
                size_t delta = h2(nodePrev.key) % m_Capacity;
                if (delta == 0)
                    delta = 1;

                for (size_t j = 1; m_Buckets[index].state == OCCUPIED; j++)
                    index = (hash + j*delta) % m_Capacity;

                m_Buckets[index] = {OCCUPIED, nodePrev.key, nodePrev.value};
            }
        }

        delete[] arrayPrev;
    }
public:
    HashMapDH()
    : m_Buckets{nullptr}
    , m_Size(0)
    , m_Capacity(7)
    , m_LoadFactor(0.0f)
    , m_LoadCapacity(0.75f)
    {
        m_Buckets = new Node[m_Capacity];
    }
    ~HashMapDH()
    {
        delete[] m_Buckets;
    }

    void Insert(unsigned long long key, const T& value)
    {
        if ((m_LoadFactor = m_Size / m_Capacity) > m_LoadCapacity)
            reallocate(2.0f);

        const size_t hash = h1(key);
        size_t index = h1(key) % m_Capacity;
        size_t delta = h2(key) % m_Capacity;
        if (delta == 0)
            delta = 1;

        // std::cout << "Inserting!" << std::endl;
        for (size_t i = 1; m_Buckets[index].state == OCCUPIED; i++)
        {
            // printf("step: %ld, capacity: %ld\n Index: %ld, I: %ld\n", delta, m_Capacity, index);
            if (m_Buckets[index].key == key)
            {
                m_Buckets[index].value = value;
                return;
            }

            index = (hash + i*delta) % m_Capacity;
        }
        m_Buckets[index] = {OCCUPIED, key, value};
        m_Size++;   
    }
    const T* const Find(unsigned long long key) const
    {
        const size_t hash = h1(key);
        size_t index = h1(key) % m_Capacity;
        size_t delta = h2(key) % m_Capacity;
        if (delta == 0)
            delta = 1;

        for (size_t i = 1; m_Buckets[index].state != EMPTY; i++)
        {
            if (m_Buckets[index].key == key)
            {
                const T* ptr = nullptr;
                if (m_Buckets[index].state == OCCUPIED)
                    ptr = &m_Buckets[index].value;

                return ptr;
            }

            index = (hash + i*delta) % m_Capacity;
        }
        return nullptr;
    }

    void Erase(unsigned long long key)
    {
        const size_t hash = h1(key);
        size_t index = h1(key) % m_Capacity;
        size_t delta = h2(key) % m_Capacity;
        if (delta == 0)
            delta = 1;

        for (size_t i = 1; m_Buckets[index].state != EMPTY; i++)
        {
            if (m_Buckets[index].key == key)
            {
                if (m_Buckets[index].state == OCCUPIED)
                {
                    m_Buckets[index].state = RESERVED;
                    m_Size--;
                }
                return;
            }

            index = (hash + i*delta) % m_Capacity;
        }
    }

    inline size_t Size() const {return m_Size;}
};
