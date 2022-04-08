#pragma once

#include <vector>

template<class T> class HashMap;

template<class T> class LinkedList
{
private:
    struct Node
    {
        unsigned long long key;
        T value;
        Node* next;
    };
private:
    Node* m_Head;
    size_t m_Size;

public:
    friend class HashMap<T>;
    
    LinkedList();
    ~LinkedList();

    void PushFront(unsigned long long key, const T& value);

    bool Remove(unsigned long long key);
    
    const T* const Get(unsigned long long key) const;
    T* const Get(unsigned long long key);
};

#include <LinkedList.tpp>