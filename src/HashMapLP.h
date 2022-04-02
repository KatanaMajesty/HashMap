#pragma once

enum State
{
    EMPTY, OCCUPIED, RESERVED
};

// Linear Probing
template<class T> class HashMapLP
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
    size_t hash(unsigned long long key) const 
    {
        return ((7 * key - 13) % 234755096012779) % m_Capacity;
    }

    void reallocate(float multiplier)
    {
        size_t capacityPrev = m_Capacity;
        m_Capacity *= multiplier;

        Node* buckets = m_Buckets;
        m_Buckets = new Node[m_Capacity];

        for (size_t i = 0; i < capacityPrev; i++)
        {
            Node& nodePrev = buckets[i];
            if (nodePrev.state == OCCUPIED)
            {
                size_t index = hash(nodePrev.key);
                while (m_Buckets[index].state == OCCUPIED)
                    index = (index + 1) % m_Capacity;

                m_Buckets[index] = nodePrev;           
            }
        }

        delete[] buckets;
    }
public:
    HashMapLP()
    : m_Buckets(nullptr)
    , m_Size(0)
    , m_Capacity(4)
    , m_LoadFactor(0.0f)
    , m_LoadCapacity(0.55f)
    {
        m_Buckets = new Node[m_Capacity];
    }
    ~HashMapLP()
    {
        delete[] m_Buckets;
    }

    void Insert(unsigned long long key, const T& value)
    {
        if ((m_LoadFactor = m_Size / m_Capacity) >= m_LoadCapacity)
            reallocate(2.0f);

        size_t index = hash(key);
        while (m_Buckets[index].state == OCCUPIED)
        {
            Node& node = m_Buckets[index];
            if (node.key == key)
            {
                node.value = value;
                return;
            }
            index = (index + 1) % m_Capacity;
        }

        m_Buckets[index] = {OCCUPIED, key, value};
        m_Size++;
    }
    
    const T* const Find(unsigned long long key) const
    {
        size_t index = hash(key);
        while (m_Buckets[index].state != EMPTY)
        {
            Node& node = m_Buckets[index];
            if (node.key == key)
            {
                const T* ptr = nullptr;
                if (node.state == OCCUPIED)
                    ptr = &node.value;

                return ptr;
            }
            index = (index + 1) % m_Capacity;
        }
        return nullptr;
    }

    void Erase(unsigned long long key)
    {
        size_t index = hash(key);
        while (m_Buckets[index].state != EMPTY)
        {
            Node& node = m_Buckets[index];
            if (node.key == key)
            {
                if (node.state == OCCUPIED)
                {
                    node.state = RESERVED;
                    m_Size--;
                }
                return;
            }
            index = (index + 1) % m_Capacity;
        }
    }

    constexpr size_t Size() {return m_Size;}
};