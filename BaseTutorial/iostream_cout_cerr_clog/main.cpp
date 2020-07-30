#include <iostream>

using namespace std;

enum index{underflow, overflow};

int array_index(int* aA, int aN, int aIndex)
{
    if (aIndex < 0)
        throw underflow;
    if (aIndex > aN-1)
        throw overflow;
    return aA[aIndex];
}

int main()
{
    int* A = new int[10];
    for (int i=0; i<10; i++)
    {
        A[i] = i;
    }

    try
    {
        cout << array_index(A, 10, 6) << endl;  //先写入缓冲区，待清扫缓冲区时，再将内容输出到显示器
    }
    catch (index e)
    {
        if (e == underflow)
            cerr << "index underflow!" << endl; //不经过缓冲区，直接将错误内容输出到显示器
        if (e == overflow)
            clog << "index overflow!" << endl;  //先写入缓冲区，待清扫缓冲区时，再将错误内容输出到显示器
    }

    try
    {
        cout << array_index(A, 10, -1) << endl;
    }
    catch (index e)
    {
        if (e == underflow)
            cerr << "index underflow!" << endl;
        if (e == overflow)
            clog << "index overflow!" << endl;
    }

    try
    {
        cout << array_index(A, 10, 15) << endl;
    }
    catch (index e)
    {
        if (e == underflow)
            cerr << "index underflow!" << endl;
        if (e == overflow)
            clog << "index overflow!" << endl;
    }

    return 0;
}
