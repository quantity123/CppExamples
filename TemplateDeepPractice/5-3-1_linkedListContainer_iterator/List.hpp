#ifndef LIST_HPP
#define LIST_HPP
#include <stdexcept>
#include "ListIterator.hpp"

//链表节点
template<typename T>
class ListNode
{
public:
    using ValueType = T;
    using ReferenceType = T&;
    using ConstReferenceType = const T&;
    ValueType mValue;
    ListNode* mPrev;
    ListNode* mNext;
    ListNode(const T& aValue, ListNode* aPrev, ListNode* aNext)
        : mValue(aValue), mPrev(aPrev), mNext(aNext)
    {
    }
};

//链表
template<typename T>
class List
{
private:
    using NodeType = ListNode<T>;
    NodeType* mHead;
public:
    using Iterator = ListIterator<NodeType>;
    List()
        : mHead(nullptr)
    {
    }
    ~List()
    {
        while (mHead != nullptr)
        {
            NodeType* n = mHead;
            mHead = mHead->mNext;
            delete n;
        }
    }
    //表头插入节点
    void pushFront(const T& v)
    {
        mHead = new NodeType(v, 0, mHead);
        if (mHead->mNext != nullptr)
        {
            mHead->mNext->mPrev = mHead;
        }
    }
    //表头删除节点
    void popFront()
    {
        if (mHead != nullptr)
        {
            NodeType* n = mHead;
            mHead = mHead->mNext;
            mHead->mPrev = nullptr;
            delete n;
        }
    }
    //指定位置后面插入节点
    void insert(Iterator it, const T& v)
    {
        NodeType* n = it.mPos;
        if (n != nullptr)
        {
            NodeType* newNode = new NodeType(v, n, n->mNext);
            newNode->mNext->mPrev = newNode;
            n->mNext = newNode;
        }
    }
    //删除指定节点
    void erase(Iterator& it)
    {
        NodeType* n = it.mPos;
        ++it;   //将迭代器指向下一个节点
        if (n != nullptr)
        {
            if (n->mNext != nullptr)
            {
                n->mNext->mPrev = n->mPrev;
            }
            if (n->mPrev != nullptr)
            {
                n->mPrev->mNext = n->mNext;
            }
            if (mHead == n)
            {
                mHead = n->mNext;
            }
            delete n;
        }
    }
    bool isEmpty() const
    {
        return mHead == nullptr;
    }
    //返回指向链表头节点的迭代器
    Iterator begin()
    {
        return Iterator(mHead);
    }
    //空迭代器是链表尾部
    Iterator end()
    {
        return Iterator();
    }
};

#endif // LIST_HPP
