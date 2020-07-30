#include <iostream>

using namespace std;

bool testReference1(int& i)
{
    i += 1;
    return true;
}

int main()
{
    int i = 1;
    if (testReference1(i))
        cout << i << endl;
    else
        cout << "false" << endl;
    return 0;
}
