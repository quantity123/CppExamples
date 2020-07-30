#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
    Object(int aID);
    ~Object();
    int getID() const;
private:
    int mID{0};
};

using UniqueObjectPtr = unique_ptr<Object>;

Object::Object(int aID)
{
    cout << "created object" << endl;
    mID = aID;
}

Object::~Object()
{
    cout << "destroy object" << endl;
}

int Object::getID() const
{
    return mID;
}

int main()
{
    UniqueObjectPtr uop{new Object{10}};
    //UniqueObjectPtr uop2{uop};    //报错，unique_ptr只能唯一管理一个指针
    auto p = uop.get();
    if (p)
    {
        cout << p->getID() << endl;
        cout << uop->getID() << endl;
    }
    //auto p1 = uop.release();   //手动获取对象指针并delete释放
    //delete p1;

    //uop.reset()   //删除了new object对象
    uop.reset(new Object{15});  //删除前面的object对象，重新创建新的object对象

    return 0;
}
