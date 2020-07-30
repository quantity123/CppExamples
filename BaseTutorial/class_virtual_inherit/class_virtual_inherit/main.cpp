#include <iostream>

using namespace std;

class A
{
public:
    void setX(const unsigned& aX);
    const unsigned& getX() const;
private:
    unsigned mX;
};

void A::setX(const unsigned& aX)
{
    mX = aX;
}

const unsigned& A::getX() const
{
    return this->mX;
}

class B: virtual public A   //增加了virtual关键字虚拟继承，去掉就是普通继承，虚拟继承让子类多重继承类时候只会得到一份来自父类的数据
{
public:
    void setY(const unsigned& aY);
    const unsigned& getY() const;
private:
    unsigned mY;
};

void B::setY(const unsigned& aY)
{
    mY = aY;
}

const unsigned& B::getY() const
{
    return mY;
}

class C: virtual public A   //增加了virtual关键字虚拟继承，去掉就是普通继承，虚拟继承让子类多重继承类时候只会得到一份来自父类的数据
{
public:
    void setZ(const unsigned& aZ);
    const unsigned& getZ() const;
private:
    unsigned mZ;
};

void C::setZ(const unsigned& aZ)
{
    mZ = aZ;
}

const unsigned& C::getZ() const
{
    return mZ;
}

class D: public B, public C //这里B,C 都是继承A，但是D只会有一份A的父类数据
{
public:
private:
};

int main()
{

    return 0;
}
