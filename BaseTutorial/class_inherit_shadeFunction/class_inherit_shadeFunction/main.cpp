#include <iostream>

using namespace std;

class Base
{
public:
    virtual void vir1()
    {
        cout << "Base vir1" << endl;
    }
    virtual void vir2()
    {
        cout << "Base vir2" << endl;
    }
    virtual ~Base(){};
};

class Derived: public Base
{
public:
    void vir1() //覆盖了父类虚函数
    {
        //Base::vir1()  //调用父类vir1()函数
        cout << "derived vir1" << endl;
    }
    void vir2(int i)    //父类是虚函数那么子类函数也是构成遮蔽关系，尽量不创造出遮蔽关系函数，用不同的名字命名函数。
    {
        cout << "derived vir2" << endl;
    }
    ~Derived(){};
};

int main()
{
    Base* p;
    p = new Derived;
    p->vir1();
    p->vir2();  //遮蔽关系的函数声明的指针或引用是哪个类调用的函数就是哪个类，这里调用Base类的vir2函数。
    delete p;

    Derived* p1;
    p1 = new Derived;
    p1->vir1();
    p1->vir2(3);    //遮蔽关系的函数声明的指针或引用是哪个类调用的函数就是哪个类，这里调用Derived类的vir2函数。
    delete p1;
    return 0;
}
