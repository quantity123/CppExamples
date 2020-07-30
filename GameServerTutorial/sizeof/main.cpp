#include <iostream>

using namespace std;

class A
{
};

class B
{
    char m_data;
};

class C
{
    char m_data[100];
};

class D
{
    char* m_data;
    D()
    {
        m_data = new char[100];
    }
    ~D()
    {
        delete[] m_data;
    }
};

static void unsignedAndSigned()
{
    size_t a = 10;
    int b = -1;

    cout << a << endl;
    cout << b << endl;
    if (b < a)  //size_t 属于无符号unsigned int类型，所以不能与int比较大小。
    {
        cout << "right\n";
    }
    else
    {
        cout << "bad\n";
    }
}

int main()
{
    cout << "bool sizeof " << sizeof(bool) << endl;
    cout << "char sizeof " << sizeof(char) << endl;
    cout << "int sizeof " << sizeof(int) << endl;
    char data[10];
    char* pData = data;
    cout << "char data[10] sizeof " << sizeof(data) << endl;
    cout << "char* sizeof " << sizeof(pData) << endl;
    cout << "A sizeof " << sizeof(A) << endl;
    cout << "B sizeof " << sizeof(B) << endl;
    cout << "C sizeof " << sizeof(C) << endl;
    cout << "D sizeof " << sizeof(D) << endl;
    cout << "size_t sizeof " << sizeof(size_t) << endl;
    cout << "ssize_t sizeof " << sizeof(ssize_t) << endl;
    cout << "blksize_t sizeof " << sizeof(blksize_t) << endl;
    unsignedAndSigned();
    return 0;
}
