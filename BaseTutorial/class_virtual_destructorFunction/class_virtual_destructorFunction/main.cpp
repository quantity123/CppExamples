#include <iostream>

using namespace std;

class Base
{
public:
    Base();
    virtual ~Base();    //只要当前类声明了virtual虚函数关键字，那么只要继承当前类的同名函数都是虚函数。
private:
    unsigned* mA;
};

Base::Base()
{
    cout << "Base constructor!" << endl;
    mA = new unsigned[10];
}

Base::~Base()
{
    cout << "Base destructor!" << endl;
    delete[] mA;
}

class Derived: public Base
{
public:
    Derived();
    ~Derived();
private:
    unsigned* mB;
};

Derived::Derived()
{
    cout << "Derived constructor!" << endl;
    mB = new unsigned[100];
}

Derived::~Derived()
{
    cout << "Derived destructor!" << endl;
    delete[] mB;
}

int main()
{
    Base* p;
    p = new Derived;
    delete p;
    return 0;
}
