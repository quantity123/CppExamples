#include <iostream>
#include <array>

using namespace std;

int main()
{
    int abc[10];   //数组未初始化
    array<int, 5> a;    //模板数组未初始化, 固定式数组，对原生数组的封装，内存分配在栈上，绝对不会重新分配内存，可以随机访问元素。
    array<int, 5> b{};
    for (auto i : b)
    {
        cout << i << endl;
    }

    array<int, 5> obj{1, 2, 3, 4, 5};
    for (auto i : obj)
    {
        cout << i << endl;
    }
    cout << obj[1] << endl; //超过了边界取值并不报错
    cout << obj.at(1) << endl;  //超过了边界取值会报错
    cout << obj.front() << endl;    //第一个
    cout << obj.back() << endl; //最后一个
    obj.fill(9);
    for (auto i : obj)
    {
        cout << i << endl;
    }

    return 0;
}
