#include <iostream>
#include <string>

using namespace std;

class Array
{
public:
    Array();
    Array(int n);
    int getLength() const;
    int& operator[](int i); //下标操作符必须以类的成员函数的形式进行重载。
    const int& operator[](int i) const;
private:
    int mLength;
    int* mNum;
};

Array::Array()
{
    mLength = 0;
    mNum = nullptr;
}

Array::Array(int aN)
{
    mLength = aN;
    try
    {
        mNum = new int[aN];
    }
    catch (bad_alloc)
    {
        cerr << "allocate storage failure!" << endl;
        throw;
    }
}

int& Array::operator[](int i)
{
    if (i < 0 || i >= mLength)
        throw string("out of bounds");
    return mNum[i];
}

const int& Array::operator[](int i) const
{
    if (i < 0 || i >= mLength)
        throw string("out of bounds");
    return mNum[i];
}

int Array::getLength() const
{
    return mLength;
}

void dispaly(const Array& aA)
{
    for (int i=0; i<aA.getLength(); i++)
    {
        cout << aA[i] << endl;
    }
}

int main()
{
    Array A(5);
    int i;
    try
    {
        for (i=0; i<A.getLength(); i++)
        {
            A[i] = i;   //A[]使用的是Array类里面重载的下标[]操作符
        }
        for (i=0; i<6; i++)
            cout << A[i] << endl;
    }
    catch (string s)
    {
        cerr << s << ", i = " << i << endl;
        return -1;
    }
    return 0;
}
