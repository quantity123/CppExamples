#include <iostream>

using namespace std;

typedef int qttint;

qttint ddd = 200;

const int *Search1(const int *a, int n, int val)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (a[i] == val)
            return &a[i];
    }
    return nullptr;
}

void pointSearch()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 7;
    int *point;
    point = const_cast<int*>(Search1(arr, 10, val));
    if (point == nullptr)
        cout << "pointSearch not fond val in array";
    else
        cout << "pointSearch have found the val in array, val = " << *point << endl;
}

const int &NullReferance = -1;

const int &Search2(const int *a, int n, int val)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (a[i] == val)
            return a[i];
    }
    return NullReferance;
}

void referenceSearch()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 7;
    int &i = const_cast<int&>(Search2(arr, 10, val));
    if (i == -1)
        cout << "referenceSearch not fond val in array";
    else
        cout << "referenceSearch have found the val in array, val = " << i << endl;
}

class Base
{
public:
    virtual ~Base(){}
    virtual void m()
    {
        cout << "m" << endl;
    }
};

class Derived: public Base
{
public:
    virtual void f()
    {
        cout << "f" << endl;
    }
};

int main()
{
    cout << ::ddd << endl;

    int a = 10, b = 20;

    double result = static_cast<double>(a) / static_cast<double>(b);
    cout << result << endl;





    const int i = 20;
    const int *p = &i;
    int *q;

    q = const_cast<int*>(p);
    *q = 30;
    cout << i << " " << *p << " " << *q << endl;
    cout << &i << " " << p << " " << q << endl;





    pointSearch();
    referenceSearch();





    int i2 = 10;
    int *p2 = &i2;//new int;
    double *d = reinterpret_cast<double*>(p2);
    cout << *d << endl;





    //Base* der;
    Derived* der;
    //der = static_cast<Derived*>(new Base);
    der = dynamic_cast<Derived*>(new Base);  //Base类中m函数必须是virtual虚函数。
    if (der != nullptr)
    {
        cout << "new Base Convert success!" << endl;
        der->m();
        der->f();
        delete der;
    }
    else
    {
        cout << "new Base Convert not safe!" << endl;
    }

    Base* ba;
    //ba = static_cast<Base*>(new Derived);
    ba = dynamic_cast<Base*>(new Derived);  //上面转换失败，是不能将基类对象指针转换为指向派生类对象指针，这里转换成功，可以将派生类对象的指针转换为指向基类对象的指针，只有多态类类型(继承关系的类)转换才能用dynamic_cast,只能转换指针或引用类型
    if (ba != nullptr)
    {
        cout << "new Derived Convert success!" << endl;
        ba->m();
        delete ba;
    }
    else
    {
        cout << "new Derived Convert not safe!" << endl;
    }

    return 0;
}
