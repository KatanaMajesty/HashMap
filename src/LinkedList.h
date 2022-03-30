#pragma once

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
    
    LinkedList()
    : m_Head(nullptr), m_Size(0)
    {
    }
    ~LinkedList()
    {
        Node* node = m_Head;
        Node* prev = nullptr;
        while (node)
        {
            prev = node;
            node = node->next;
            delete prev;
        }
    }

    void PushFront(unsigned long long key, const T& value)
    {
        Node* node = new Node {key, value, m_Head};
        m_Head = node;
        m_Size++;
    }

    bool Remove(unsigned long long key)
    {
        Node* node = m_Head;
        Node* prev = nullptr;
        while (node)
        {
            if (node->key == key)
            {
                if (prev)
                    prev->next = node->next;
                else m_Head = node->next;

                delete node;
                m_Size--;
                return true;
            }

            prev = node;
            node = node->next;
        }
        return false;
    }
    
    const T* const Get(unsigned long long key) const
    {
        Node* node = m_Head;
        while (node)
        {
            if (node->key == key)
                return &node->value;
        }
        return nullptr;
    }

    T* const Get(unsigned long long key)
    {
        Node* node = m_Head;
        while (node)
        {
            if (node->key == key)
                return &node->value;
            
            node = node->next;
        }
        return nullptr;
    }
};