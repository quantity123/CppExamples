#include <iostream>

using namespace std;

int main()
{
    char a[13];
    cin.get(a, 13, '7');
    cout << a << endl;
    cin.ignore();
    cin.get(a, 13, '7');
    cout << a << endl;
    cin.putback(a[8]);  //把字符重新放入cin缓冲区当前指针指向位置，后面仍然会读取该字符
    cin.putback(a[7]);
    cin.get(a, 13);
    cout << a << endl;
    return 0;
}
