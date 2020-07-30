#include <iostream>

using namespace std;

class Base
{
public:
    virtual void display();
};

void Base::display()
{
    cout << "Base class!" << endl;
}

class Derived: public Base
{
public:
    void display() override;
};

void Derived::display()
{
    cout << "Derived class!" << endl;
}

int main()
{
    Base* p;    //基类指针可以接收基类对象实例或任何子类对象实例，所以这就是多态了。

    p = new Base();
    p->display();
    delete p;

    p = new Derived();
    p->display();
    delete p;
    return 0;
}
