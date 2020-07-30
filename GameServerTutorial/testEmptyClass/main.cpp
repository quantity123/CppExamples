#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstring>

using namespace std;

template<typename T>
struct EmptyHelper : T
{
    int group[256];
};

struct EmptyHelper2
{
    int group[256];
};

template<typename T>
bool isEmptyClass()
{
    return sizeof(EmptyHelper2) == sizeof(EmptyHelper<T>);
}

struct Empty{};

struct DummyEmpty
{
    int a;
};

void dummyMalloc(char* p)
{
    p = (char*)malloc(8);
}

int main()
{
    cout << "Empty is " << sizeof(Empty) << endl;   //空类为了被实例化后在内存里有独一无二的地址，编译器会隐含给它加一个字节。
    cout << "DummyEmpty is " << sizeof(DummyEmpty) << endl;
    cout << "Empty is " << isEmptyClass<Empty> << endl;
    cout << "DummyEmpty is " << isEmptyClass<DummyEmpty> << endl;

    char s[] = "Hello world";
    //char s[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    dummyMalloc(s);
    strcpy(s, "Hi Hello world\n");    //如果复制的长度大于上面 s 字符数组初始化的字符串，那么报错
    printf(s);

    return 0;
}
