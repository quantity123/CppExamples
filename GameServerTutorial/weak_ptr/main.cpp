#include <iostream>
#include <memory>

using namespace std;

class Object2;
using Object2Ptr = shared_ptr<Object2>;
using weakObject2Ptr = weak_ptr<Object2>;

class Object1
{
public:
    weakObject2Ptr op2;
    Object1();
    ~Object1();
};

class Object1;
using Object1Ptr = shared_ptr<Object1>;
using weakObject1Ptr = weak_ptr<Object1>;

class Object2
{
public:
    weakObject1Ptr po1;
    Object2();
    ~Object2();
};

Object1::Object1()
{
    cout << "object1 created" << endl;
}

Object1::~Object1()
{
    cout << "object1 destroy" << endl;
}

Object2::Object2()
{
    cout << "Object2 created" << endl;
}

Object2::~Object2()
{
    cout << "object2 destroy" << endl;
}

int main()
{
    Object1Ptr op1(new Object1);
    Object2Ptr op2(new Object2);
    op1->op2 = op2;
    op2->po1 = op1;
    return 0;
}
