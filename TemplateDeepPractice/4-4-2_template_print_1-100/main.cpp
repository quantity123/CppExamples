#include <iostream>

using namespace std;

template<int i>
void print()
{
    print<i-1>();   //调用自身递归
    cout << i << endl;
}

//通过调用下面这个模板函数特例终止上面的递归
template<>
void print<1>()
{
    cout << 1 << endl;
}

int main()
{
    print<100>();
    return 0;
}
