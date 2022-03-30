#pragma once

#include <LinkedList.h>

template<class T> class HashMap
{
private:
    typedef typename LinkedList<T>::Node Node;

    LinkedList<T>* m_Buckets;
    size_t m_Capacity;
    size_t m_Size;
    float m_LoadFactor;
    float m_LoadCapacity;

    size_t hash(unsigned long long key) const 
    {
        return ((7 * key - 13) % 558249577) % m_Capacity;
    }

    void reallocate(float multiplier)
    {
        if (multiplier <= 1.0f)
            multiplier = 1.5f;

        // change capacity
        size_t capacity = m_Capacity * multiplier;
        size_t prevCapacity = m_Capacity;
        m_Capacity = capacity;

        LinkedList<T>* buckets = new LinkedList<T>[m_Capacity];
        

        for (size_t i = 0; i < prevCapacity; i++)
        {
            LinkedList<T>& list = m_Buckets[i];
            Node* node = list.m_Head;
            while (node)
            {
                // get index in new array
                size_t index = hash(node->key);
                LinkedList<T>& list = buckets[index];
                T* const ptr = list.Get(node->key);
                if (ptr)
                {
                    *ptr = node->value;
                    return;
                }
                list.PushFront(node->key, node->value);
                node = node->next;
            }
        }

        delete[] m_Buckets;
        m_Buckets = buckets;
    }
public:
    HashMap()
    : m_Buckets(nullptr)
    , m_Capacity(4)
    , m_Size(0)
    , m_LoadFactor(0.0f)
    , m_LoadCapacity(0.9f)
    {
        m_Buckets = new LinkedList<T>[m_Capacity];
    }
    ~HashMap()
    {

    }

    void Insert(unsigned long long key, const T& value)
    {
        if ((m_LoadFactor = m_Size / m_Capacity) > m_LoadCapacity)
            reallocate(2.0f);

        size_t index = hash(key);
        LinkedList<T>& list = m_Buckets[index];
        T* const ptr = list.Get(key);
        if (ptr)
        {
            *ptr = value;
            return;
        }
        list.PushFront(key, value);
        m_Size++;
    }

    const T* const Find(unsigned long long key) const
    {
        size_t index = hash(key);
        LinkedList<T>& list = m_Buckets[index];
        return list.Get(key);
    }

    T* const Find(unsigned long long key)
    {
        size_t index = hash(key);
        LinkedList<T>& list = m_Buckets[index];
        return list.Get(key);
    }

    void Erase(unsigned long long key)
    {
        size_t index = hash(key);
        LinkedList<T>& list = m_Buckets[index];
        if (list.Remove(key))
            m_Size--;
    }

    constexpr size_t Size() {return m_Size;}
};