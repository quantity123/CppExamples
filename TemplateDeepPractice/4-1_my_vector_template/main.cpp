#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
    MyVector<char> vi(2);
    MyVector<bool> vb(2);
    for (unsigned int i=0; i<20; ++i)
    {
        vi.pushBack('a'+i);
        vb.pushBack((i%4) == 0);
    }
    cout << "MemSize of MyVector<char> is " << vi.getMemSize() << endl;
    cout << "MemSize of MyVector<bool> is " << vb.getMemSize() << endl;
    for (unsigned int i=0; i<20; ++i)
    {
        cout << " " << vi[i];
    }
    cout << endl;
    for (unsigned int i=0; i<20; ++i)
    {
        cout << " " << vb[i];
    }
    cout << endl;
    return 0;
}
