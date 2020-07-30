#include <iostream>

using namespace std;

typedef unsigned long ulong1;
using ulong2 = unsigned long;   //C++11 新语法把using 可以替换 typedef的类型定义

int main()
{
    ulong1 l1 = 111;
    ulong2 l2 = 222;
    cout << l1 << " " << l2 << endl;
    return 0;
}
