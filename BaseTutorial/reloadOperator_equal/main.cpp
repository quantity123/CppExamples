#include <iostream>

using namespace std;

class Array
{
public:
    Array()
    {
        mLength = 0;
        mNum = nullptr;
    }
    Array(int* aA, int aN);
    Array(Array& aArr);
    ~Array();
    Array& operator=(const Array& aArr);
    int* getAddress()
    {
        return mNum;
    }
    int getLength()
    {
        return mLength;
    }
    void setNum(int aValue, int aIndex);
    void display();
private:
    int mLength;
    int* mNum;  //类中没有包含需要动态分配内存的指针成员变量时，可以使用默认的 = 操作符或拷贝构造函数，无需重载 = 操作符。
};

Array::Array(Array& aArr)
{
    if (aArr.mLength > 0)
    {
        mLength = aArr.mLength;
        mNum = new int[mLength];
        for (int i=0; i<mLength; i++)
        {
            mNum[i] = aArr.mNum[i];
        }
    }
    else
    {
        mLength = 0;
        mNum = nullptr;
    }
}

Array::Array(int* aA, int aN)
{
    mNum = new int[aN];
    mLength = aN;
    for (int i=0; i<mLength; i++)
    {
        mNum[i] = aA[i];
    }
}

Array::~Array()
{
    if (mLength > 0)
    {
        delete[] mNum;
    }
}

Array& Array::operator=(const Array& aArr)
{
    if (this != &aArr)
    {
        if (aArr.mNum != nullptr)
        {
            mLength = aArr.mLength;
            delete[] mNum;
            mNum = new int[mLength];
            for (int i=0; i<mLength; i++)
            {
                mNum[i] = aArr.mNum[i];
            }
        }
        else
        {
            mLength = 0;
            mNum = nullptr;
        }
    }
    return *this;
}

void Array::setNum(int aValue, int aIndex)
{
    if (aIndex < mLength)
    {
        mNum[aIndex] = aValue;
    }
    else
    {
        cout << "index out of range!" << endl;
    }
}

void Array::display()
{
    for (int i=0; i<mLength; i++)
    {
        cout << mNum[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    Array arr1(A, 5);
    cout << "arr1: ";
    arr1.display();
    cout << "arr1.getAddress: ";
    cout << arr1.getAddress() << endl;
    Array arr2;
    arr2 = arr1;    //这个 = 操作符在类中被重载。
    cout << "arr2: ";
    arr2.display();
    cout << "arr2.getAddress: ";
    cout << arr2.getAddress() << endl;
    return 0;
}
