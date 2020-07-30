#include <iostream>

using namespace std;

void qttSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int &valplus(int &i)
{
    i += 6;
    return i;
}

int main()
{
    int a = 10;
    const int &b = a;
    //b = 20;   //报错, const 的引用不能修改值
    a = 20;

    int c1 = 30, c2 = 40;

    cout << c1<< " " << c2 << endl;
    qttSwap(c1, c2);
    cout << c1 << " " << c2 << endl;

    int i = 50;
    int retI = valplus(i);
    cout << retI << endl;

    return 0;
}
