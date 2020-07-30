#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP
#include <stdexcept>

template<typename T>
class List;

template<typename N>
class ListIterator
{
private:
    N* mPos;
    template<typename T>
    friend class List;
public:
    //重命名各种类型名方便其它模板提取
    using SelfType = ListIterator<N>;   //指定自身模板类的特例类型
    using ValueType = typename N::ValueType;
    using ReferenceType = typename N::ReferenceType;    //当使用N::ReferenceType嵌套标识类型的时候，前面必须用typename修饰，否则编译器不知道什么类型
    using ConstReferenceType = typename N::ConstReferenceType;
    ListIterator()
        : mPos(nullptr)
    {
    }
    ListIterator(N* aPos)
        : mPos(aPos)
    {
    }
    bool operator!=(const SelfType& aRight) const
    {
        return mPos != aRight.mPos;
    }
    bool operator==(const SelfType& aRight) const
    {
        return mPos == aRight.mPos;
    }
    SelfType& operator++()
    {
        if (mPos != nullptr)
            mPos = mPos->mNext;
        return *this;
    }
    SelfType& operator--()
    {
        if (mPos != nullptr)
            mPos = mPos->mPrev;
        return *this;
    }
    ReferenceType operator*()
    {
        if (mPos != nullptr)
            return mPos->mValue;
        else
            throw std::runtime_error("dereferencing null iterator!");
    }
};

#endif // LISTITERATOR_HPP
