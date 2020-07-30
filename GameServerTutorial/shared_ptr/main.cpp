#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
    Object(int id)
    {
        mId = id;
        cout << "init ojb " << mId << endl;
    }
    ~Object()
    {
        cout << "free ojb " << mId << endl;
    }
    int getID()
    {
        return mId;
    }
private:
    int mId{};
};

using ObjedtPtr = shared_ptr<Object>;

void print(ObjedtPtr obj)
{
    cout << "call print obj1 count is " << obj.use_count() << endl;
}

void printRef(const ObjedtPtr& obj)
{
    cout << "call printRef obj1 count is " << obj.use_count() << endl;
}

void deleteObject(Object* obj)
{
    delete obj;
}

void useDeleter()
{
    ObjedtPtr obj{new Object{2}, deleteObject};
}

int main()
{
    ObjedtPtr obj0;    //默认管理的为空指针
    cout << "shared_ptr obj0 count is " << obj0.use_count() << endl;

    ObjedtPtr obj1{new Object{10}}; //建立实例初始化一个对象object
    cout << "shared_ptr obj1 count is " << obj1.use_count() << endl;

    ObjedtPtr obj2{obj1};
    cout << "shared_ptr obj2 count is " << obj2.use_count() << endl;
    cout << "shared_ptr obj1 count is " << obj1.use_count() << endl;

    ObjedtPtr obj3 = obj1;
    cout << "shared_ptr obj3 count is " << obj3.use_count() << endl;
    cout << "shared_ptr obj1 count is " << obj1.use_count() << endl;

    //obj2.reset();
    obj2 = nullptr;
    cout << "shared_ptr obj2 count is " << obj2.use_count() << endl;
    cout << "shared_ptr obj1 count is " << obj1.use_count() << endl;
    cout << "shared_ptr obj3 count is " << obj3.use_count() << endl;

    ObjedtPtr obj4;
    obj3.swap(obj4);
    cout << "shared_ptr obj3 count is " << obj3.use_count() << endl;
    cout << "shared_ptr obj4 count is " << obj4.use_count() << endl;
    swap(obj4, obj3);
    cout << "shared_ptr obj3 count is " << obj3.use_count() << endl;
    cout << "shared_ptr obj4 count is " << obj4.use_count() << endl;

    print(obj1);    //传对象值参数,函数内部会有对象拷贝导致use_count+1
    printRef(obj1); //引用就不会有对象拷贝

    auto p = obj1.get();
    if (p)
        cout << "p obj1 id is " << p->getID() << endl;

    if (obj1)
    {
        cout << "obj1 id is " << obj1->getID() << endl;
    }

    if (obj1.unique())
        cout << "only one ptr in obj1" << endl;
    else
        cout << "not only one ptr in obj1" << endl;

    useDeleter();

    return 0;
}
