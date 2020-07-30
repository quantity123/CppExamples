#include <iostream>

using namespace std;

class Array
{
public:
    Array();
    Array(int& aM, int& aN);
    int& operator()(int aI, int aJ);    //括号操作符必须以类的成员函数的形式进行重载。
    const int& operator()(int aI, int aJ) const;    //因为只有常成员函数才能处理对象，所以提供一个有常量重载时候使用。
    const int& getLen1() const;
    const int& getLen2() const;
private:
    int mLen1, mLen2;
    int* mNum;
};

Array::Array()
{
    mLen1 = 0;
    mLen2 = 0;
    mNum = nullptr;
}

Array::Array(int& aM, int& aN)
{
    mLen1 = aM;
    mLen2 = aN;
    unsigned numSize = aM * aN;
    try
    {
        mNum = new int[numSize];
    }
    catch (bad_alloc)
    {
        cerr << "allocate storage failure!" << endl;
        throw;
    }
}

int& Array::operator()(int aI, int aJ)
{
    if (aI<0 || aI>=mLen1)
        throw string("1 out of bounds!");
    if (aJ<0 || aJ>=mLen2)
        throw string("2 out of bounds!");
    return mNum[aI * mLen2 + aJ];
}

const int& Array::operator()(int aI, int aJ) const
{
    if (aI<0 || aI>=mLen1)
        throw string("1 out of bounds!");
    if (aJ<0 || aJ>=mLen2)
        throw string("2 out of bounds!");
    return mNum[aI * mLen2 + aJ];
}

const int& Array::getLen1() const
{
    return mLen1;
}

const int& Array::getLen2() const
{
    return mLen2;
}

int main()
{
    int m = 3, n = 4;
    Array A(m, n);
    int i, j;
    for (i=0; i<A.getLen1(); i++)
    {
        for (j=0; j<A.getLen2(); j++)
        {
            A(i, j) = i * A.getLen2() + j;
        }
    }
    for (i=0; i<A.getLen1(); i++)
    {
        for (j=0; j<A.getLen2(); j++)
        {
            cout << A(i, j) << " ";
        }
    }
    cout << endl;

    try
    {
        cout << A(5, 3) << endl;
    }
    catch (string s)
    {
        cerr << s << endl;
    }

    try
    {
        cout << A(2, 6) << endl;
    }
    catch (string s)
    {
        cerr << s << endl;
    }
    return 0;
}
