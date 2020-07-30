#include <iostream>

using namespace std;

class Qtt
{
public:
    int i{100};
};

int main()
{
    cout << sizeof(bool) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(unsigned int) << endl;   //无符号的前面加unsigned
    cout << sizeof(long) << endl;
    Qtt qtt;
    Qtt *pQtt = &qtt;
    Qtt &refQtt = qtt;
    cout << sizeof(&qtt) << endl;
    cout << qtt.i << endl;
    cout << sizeof(pQtt) << endl;
    cout << pQtt->i << endl;
    cout << sizeof(refQtt) << endl;
    cout << refQtt.i << endl;
    return 0;
}
