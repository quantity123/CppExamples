#include <iostream>

using namespace std;

int main()
{
    char a[13];
    cin.get(a, 13, '7');    //遇到终止符 '7'停止
    cout << a << endl;
    cin.ignore();   //
    cin.get(a, 13, '7');
    cout << a << endl;
    cin.get(a, 13); //默认终止符'\n'，否则读满缓冲区a空间
    cout << a << endl;
    return 0;
}
