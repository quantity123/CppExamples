#include <iostream>
#include <stdexcept>

template<typename T>
class stack;

template<typename T>
class list_node
{
    T value;
    list_node* next;
    list_node(const T& v, list_node* n)
        : value(v), next(n)
    {
    }
    friend class stack<T>;
};

template <typename T = int>
class stack
{
    using node_type = list_node<T>;
    node_type* head;
    stack operator=(const stack&)
    {
    }
public:
    stack()
        : head(0)
    {
    }
    ~stack()
    {
        while (!empty())
            pop();
    }
    bool empty() const
    {
        return head == 0;
    }
    const T& top() const// throw(std::runtime_error)
    {
        if (empty())
            throw std::runtime_error("stack is empty.");
        return head->value;
    }
    void push(const T& v)
    {
        head = new node_type(v, head);
    }
    void pop();
};

template<typename T>
void stack<T>::pop()
{
    if (head)
    {
        node_type* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T = int>
class countStack : public stack<T>
{
    unsigned int size;  //上面没有加private限定为私有成员，但是默认就是私有成员
public:
    countStack()
        : stack<T>(), size(0)
    {
    }
    void push(const T& v)
    {
        stack<T>::push(v);
        ++size;
    }
    void pop()
    {
        if (size > 0)
        {
            stack<T>::pop();
            --size;
        }
    }
    unsigned int getSize() const
    {
        return size;
    }
};
