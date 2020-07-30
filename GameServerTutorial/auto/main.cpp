#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    int mI{};
    int mI2{6};
};

static void autoValue()
{
    auto age = 10;
    auto name = string{"Yt"};
    auto height = 160.0f;
    auto weight = 72.0;
    cout << "age is type " << typeid(age).name() << endl;
    cout << "name is type " << typeid(name).name() << endl;
    cout << "height is type " << typeid(height).name() << endl;
    cout << "weight is type " << typeid(weight).name() << endl;
}

static void autoPointer()
{
    auto age = new int{10};
    auto name = "Yt";
    auto height = new float{160.0f};
    auto weight = new double{72.0};
    cout << "age is type " << typeid(age).name() << endl;
    cout << "name is type " << typeid(name).name() << endl;
    cout << "height is type " << typeid(height).name() << endl;
    cout << "weight is type " << typeid(weight).name() << endl;
}

int main()
{
    autoValue();
    autoPointer();

    int i{2};   //初始化值都用大括号{}
    i = 3;
    cout << i << endl;

    int* i2 = new int{3};
    *i2 = 4;
    cout << *i2 << endl;

    vector<int> arr1{0, 1, 2};
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int>* arr2 = new vector<int>{5, 6, 7};
    for (auto i : *arr2)
    {
        cout << i << " ";
    }
    cout << endl;
    delete arr2;

    A a;
    cout << a.mI << endl;
    cout << a.mI2 << endl;
    return 0;
}
