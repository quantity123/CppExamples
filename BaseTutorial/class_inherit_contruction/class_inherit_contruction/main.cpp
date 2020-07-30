#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "A constructor" << endl;
    };
    A(int& aX);
    ~A()
    {
        cout << "A destructor" << endl;
    }
    void setX(int& aX);
    int& getX();
private:
    int mX = 0;
};

A::A(int& aX)
{
    mX = aX;
    cout << "A constructor" << endl;
}

void A::setX(int& aX)
{
    mX = aX;
}

int& A::getX()
{
    return mX;
}

class B: public A
{
public:
    B():A()
    {
        cout << "B constructor" << endl;
    };
    B(int& aX, int& aY);
    ~B()
    {
        cout << "B destructor" << endl;
    }
    void setY(int& aY);
    int& getY();
private:
    int mY = 0;
};

B::B(int& aX, int& aY):A(aX)
{
    mY = aY;
    cout << "B constructor" << endl;
}

void B::setY(int& aY)
{
    mY = aY;
}

int& B::getY()
{
    return mY;
}

class C: public B
{
public:
    C():B()
    {
        //B::B(); //这样也是调用父类构造函数
        cout << "C constructor" << endl;
    };
    C(int& aX, int& aY, int& aZ);
    ~C()
    {
        cout << "C destructor" << endl;
    }
    void setZ(int& aZ);
    int& getZ();
    void dispaly();
private:
    int mZ = 0;
};

C::C(int& aX, int& aY, int& aZ):B(aX, aY)
{
    mZ = aZ;
    cout << "C constructor" << endl;
}

void C::setZ(int& aZ)
{
    mZ = aZ;
}

int& C::getZ()
{
    return mZ;
}

void C::dispaly()
{
    cout << "A:" << this->getX() << ", B:" << this->getY() << ", C:" << this->getZ() << endl;
}

int main()
{
    C c1;
    c1.dispaly();

    int a=10, b=20, c=30;
    C c2(a, b, c);
    c2.dispaly();
    return 0;
}
