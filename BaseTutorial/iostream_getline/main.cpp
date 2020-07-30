#include <iostream>

using namespace std;

int main()
{
    char a[13];

    cin.getline(a, 13, '3');    //a缓冲区满13个字符空间就终止, 遇到3字符也终止
    cout << a << endl;
    cin.getline(a, 13, '3');
    cout << a << endl;
    cin.getline(a, 13); //默认终止符'\n'，否则读满缓冲区a空间
    cout << a << endl;
    return 0;
}
