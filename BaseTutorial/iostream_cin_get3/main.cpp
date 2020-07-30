#include <iostream>

using namespace std;

int main()
{
    char s[10];

    while (cin.get(s, 10, '\n'))
    {
        cout << s << endl;
    }
    cout << endl;
    return 0;
}
