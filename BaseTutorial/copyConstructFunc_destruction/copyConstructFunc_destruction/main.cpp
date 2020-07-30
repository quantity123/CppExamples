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
    explicit Array(int *aA, int aN);    //有参数的构造函数要加explicit, 防止隐式创建对象
    explicit Array(Array &aArr);    //有参数的构造函数要加explicit, 防止隐式创建对象
    ~Array();
    int *getAddress()
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
    int *mNum;
};

Array::Array(int *aA, int aN)
{
    mNum = new int[aN];
    mLength = aN;
    for (int i=0; i<mLength; i++)
    {
        mNum[i] = aA[i];
    }
}

Array::Array(Array &aArr)
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

Array::~Array()
{
    if (mLength > 0)
    {
        delete[] mNum;
    }
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
    arr1.display();

    Array arr2(arr1);
    arr2.display();

    arr2.setNum(0, 3);
    arr2.display();
    arr1.display();

    cout << arr1.getAddress() << " " << arr2.getAddress() << endl;
    return 0;
}
