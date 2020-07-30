#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
public:
    virtual void m()
    {
        cout << "Base" << endl;
    }
};

class Derived: public Base
{
public:
    void m()
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    //typeid 可以用来对变量数据类型的判断
    int a;

    if (typeid(a) == typeid(int))
        cout << "int true" << endl;
    else
        cout << "int false" << endl;

    if (typeid(a) == typeid(float))
        cout << "float true" << endl;
    else
        cout << "float false" << endl;

    if (typeid(a) == typeid(int*))
        cout << "int* true" << endl;
    else
        cout << "int* false" << endl;

    double b;

    if (typeid(b) == typeid(double))
        cout << "double true" << endl;
    else
        cout << "double false" << endl;

    if (typeid(b) == typeid(float))
        cout << "float true" << endl;
    else
        cout << "float false" << endl;

    if (typeid(b) == typeid(long double))
        cout << "long double true" << endl;
    else
        cout << "long double false" << endl;

    char* c;

    if (typeid(c) == typeid(char*))
        cout << "char* true" << endl;
    else
        cout << "char* false" << endl;

    if (typeid(c) == typeid(char))
        cout << "char true" << endl;
    else
        cout << "char false" << endl;

    if (typeid(c) == typeid(string))
        cout << "string true" << endl;
    else
        cout << "string false" << endl;

    long d;

    if (typeid(d) == typeid(long))
        cout << "long true" << endl;
    else
        cout << "long false" << endl;

    if (typeid(d) == typeid(int))
        cout << "int true" << endl;
    else
        cout << "int false" << endl;






    Base* p = new Derived;  //如果Base基类中有虚函数，那么基类具有多态性，运行期动态类型 p 指向的是派生类对象，否则 p 是编译期静态类型指向基类。

    if (typeid(p) == typeid(Base*))
        cout << "p == Base* true" << endl;
    else
        cout << "p == Base* false" << endl;

    if (typeid(p) == typeid(Derived*))
        cout << "p == Derived* true" << endl;
    else
        cout << "p == Derived* false" << endl;

    if (typeid(*p) == typeid(Base))
        cout << "*p == Base true" << endl;
    else
        cout << "*p == Base false" << endl;

    if (typeid(*p) == typeid(Derived))
        cout << "*p == Derived true" << endl;
    else
        cout << "*p == Derived false" << endl;

    return 0;
}
