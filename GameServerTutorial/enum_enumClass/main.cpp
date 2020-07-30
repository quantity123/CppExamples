#include <iostream>

using namespace std;

enum Color {cRed, cGreen, cBlue};

void testEnum()
{
    Color r = cRed;
    switch (r)
    {
        case cRed:
            cout << "i'm cRed\n";
            break;
        case cGreen:
            cout << "i'm cGreen\n";
            break;
        case cBlue:
            cout << "i'm cBlue\n";
            break;
        default:
            cout << "testEnum no found\n";
    }
}

enum class NewColor : short {ncRed, ncGreen, ncBlue};   //short 指定了枚举的每个项的大小，默认不指定就是int类型

void testEnumClass()
{
    NewColor r = NewColor::ncBlue;
    switch (r)
    {
        case NewColor::ncRed:
            cout << "i'm ncRed\n";
            break;
        case NewColor::ncBlue:
            cout << "i'm ncBlue\n";
            break;
        case NewColor::ncGreen:
            cout << "i'm ncGreen\n";
            break;
        default:
            cout << "testEnumClass no found\n";
    }
}

int main()
{
    testEnum();
    testEnumClass();
    return 0;
}
