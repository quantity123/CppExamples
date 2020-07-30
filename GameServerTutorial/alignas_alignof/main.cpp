#include <iostream>

using namespace std;

struct Obj
{
    char a;
    int b;  //以最大的int为对齐
};

struct Foo
{
    int i;
    float f; //以int和float一样的大小为4个字节对齐
    char c;
};

struct Empty
{

};

struct alignas(64) Empty64
{

};

struct alignas(1) Double    //虽然alignas定义了1个字节对齐，但是结构体里面有double占用8个字节，所以还是以8字节对齐
{
    double d;
    int i;
};

int main()
{
    cout << "sizeof(Obj):" << sizeof(Obj) << endl;
    cout << "alignof(Obj):" << alignof(Obj) << endl;   //查询类型在内存里以多大的字节对齐。
    cout << "alignof(char):" << alignof(char) << endl;
    cout << "alignof(int*):" << alignof(int*) << endl;  //64位的8字节，32位的4字节。
    cout << "alignof(Foo):" << alignof(Foo) << endl;
    cout << "alignof(Empty):" << alignof(Empty) << endl; //编译器自动为空类分配了一个字节
    cout << "alignof(Empty64):" << alignof(Empty64) << endl;
    cout << "alignof(Double):" << alignof(Double) << endl;
    return 0;
}
