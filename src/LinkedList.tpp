#define LIST(x) template<class T> x LinkedList<T>

LIST()::LinkedList()
: m_Head(nullptr), m_Size(0)
{
}

LIST()::~LinkedList()
{
    Node* node = m_Head;
    while (m_Head)
    {
        node = m_Head;
        m_Head = m_Head->next;
        delete node;
    }
}

LIST(void)::PushFront(unsigned long long key, const T& value)
{
    Node* node = new Node {key, value, m_Head};
    m_Head = node;
    m_Size++;
}

LIST(bool)::Remove(unsigned long long key)
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

LIST(const T* const)::Get(unsigned long long key) const
{
    Node* node = m_Head;
    while (node)
    {
        if (node->key == key)
            return &node->value;
    }
    return nullptr;
}

LIST(T* const)::Get(unsigned long long key)
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
