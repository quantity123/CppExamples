#include <iostream>

using namespace std;

int i1;
string s1;

struct Foo
{

};

int main()
{
    int i, &ri=i;
    i = 5;
    ri = 10;
    cout << i << " " << ri << endl;

    int i2 = 0;
    string s2;

    cout << ::i1 << endl;
    cout << ::s1 << endl;
    cout << i2 << endl;
    cout << s2 << endl;

    int num1 = 50, total = 0;

    while (num1 <= 100)
    {
        total += num1;
        num1 += 1;
    }
    cout << "50+...100 = " << total << endl;

    int num2 = 10;

    while (num2 >= 0)
    {
        cout << num2 << endl;
        --num2;
    }

    int a = 0, b = 0;

    cout << "input two numbers:" << endl;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    while (a <= b)
    {
        cout << a << endl;
        ++a;
    }

    return 0;
}
