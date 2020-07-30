#include <iostream>

using namespace std;

enum index{underflow, overflow};

int array_index(int *A, int n, int index)
{
    if (index < 0)
        throw underflow;
    if (index > n-1)
        throw overflow;
    return A[index];
}

int main()
{
    int *A = new int[10];
    for (auto i=0; i<10; i++)
    {
        A[i] = i;
    }

    try
    {
        cout << array_index(A, 10, 5) << endl;
        //cout << array_index(A, 10, -1) << endl;
        cout << array_index(A, 10, 15) << endl;
        cout << "dddd" << endl; //上面报错，所以这条cout没执行
    }
    catch(index e)
    {
        if (e == underflow)
        {
            cout << "index underflow!" << endl;
            //exit(-1);
        }
        if (e == overflow)
        {
            cout << "index overflow!" << endl;
            //return -1;
        }
    }
    cout << "eeeeee" << endl;   //上面catch处理完毕继续向下执行，所以eeeee被输出

    return 0;
}
