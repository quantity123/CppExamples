#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <stdexcept>

template<typename T>
class MyVector
{
private:
    T* mArray;
    unsigned int mSize;
    unsigned int mBlockSize;
public:
    MyVector(unsigned int bsz)
        : mArray((T*)malloc(sizeof(T)*bsz)), mSize(0), mBlockSize(bsz)
    {
    }
    ~MyVector()
    {
        if (mArray)
            free(mArray);
    }
    void pushBack(const T& elem)
    {
        if (mSize >= mBlockSize)
        {
            mBlockSize *= 2;
            T* newArray = (T*)realloc(mArray, mBlockSize*sizeof(T));
            if (newArray != nullptr)
            {
                mArray = newArray;
            }
            else
            {
                free(mArray);
                mArray = nullptr;
                throw std::runtime_error("Out of memory.");
            }
        }
        mArray[mSize++] = elem;
    }
    T& operator[](unsigned int i)
    {
        return mArray[i];
    }
    const T& operator[](unsigned int i) const
    {
        return mArray[i];
    }
    unsigned int getMemSize() const
    {
        return mBlockSize * sizeof(T);
    }
};

//-----------------------MyVector特例
template<>
class MyVector<bool>    //完全特例 bool型
{
private:
    int* mArray;
    unsigned int mSize;
    unsigned int mBlockSize;
    static const unsigned int mSegSize; //类变量专属为类而服务
public:
    MyVector(unsigned int bsz = 1)
        : mArray((int*)malloc(sizeof(int)*bsz)), mSize(0), mBlockSize(bsz)
    {
    }
    ~MyVector()
    {
        if (mArray != nullptr)
        {
            free(mArray);
        }
    }
    void pushBack(bool elem)
    {
        if (mSize >= mBlockSize*mSegSize)
        {
            mBlockSize *= 2;
            int* newArray = (int*)realloc(mArray, mBlockSize*sizeof(int));
            if (newArray != nullptr)
            {
                mArray = newArray;
            }
            else
            {
                free(mArray);
                mArray = nullptr;
                throw std::runtime_error("Out of memory.");
            }
        }
        set(mSize++, elem);
    }
    void set(unsigned int i, bool elem)
    {
        if (elem)
        {
            mArray[i/mSegSize] |= (0x1 << (i%mSegSize));
        }
        else
        {
            mArray[i/mSegSize] &= ~(0x1 << (i%mSegSize));
        }
    }
    bool operator[](unsigned int i) const
    {
        return (mArray[i/mSegSize] & (0x1 << (i%mSegSize))) != 0;
    }
    unsigned int getMemSize() const
    {
        return mBlockSize * sizeof(int);
    }
};

const unsigned int MyVector<bool>::mSegSize = sizeof(int) * 8;

#endif // MYVECTOR_H
