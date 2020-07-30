#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        mX = 0;
    }
    Base(unsigned& aX)
    {
        mX = aX;
    }
    virtual ~Base(){}
    virtual void display() = 0; //只有虚函数才能成为纯虚函数。
    unsigned& getX()
    {
        return mX;
    }
private:
    unsigned mX;
};

class Derived1: public Base
{
public:
    Derived1()
    {
        mY = 0;
    }
    Derived1(unsigned& aY)
    {
        mY = aY;
    }
    ~Derived1(){}
private:
    unsigned mY;
};

class Derived2: public Base
{
public:
    Derived2()
    {
        mZ = 0;
    }
    Derived2(unsigned aA, unsigned aB):Base(aA)
    {
        mZ = aB;
    }
    ~Derived2(){}
    void display()
    {
        cout << "X=" << getX() << ", Z=" << mZ << endl;
    }
private:
    unsigned mZ;
};

int main()
{
    Derived2 d2(3, 5);
    d2.display();
    return 0;
}
