#include <iostream>
#include <string>

using namespace std;

template<typename T>
void print(T v)
{
    cout << "1 " << v << endl;
}

//模板函数特例1
template<>
void print<char>(char v)
{
    cout << "2 " << v << endl;
}

//模板函数特例2
template<>
void print<const char*>(const char* v)
{
    cout << "3 " << *v << endl;
}

//模板函数的模板重载
template<typename T, typename T1>
void print(T v)
{
    cout << "4 " << v << endl;
}

//普通函数，同名同参数不与模板函数冲突，而且优先级最高
void print(char v)
{
    cout << "5 " << v << endl;
}

int main()
{
    char c('a');
    print(c);
    print(&c);  //没有匹配4，是因为c变量不是const char

    const char c2('b');
    print(c2);
    print(&c2); //匹配4，是因为变量是const char，但是函数参数是const char*指针，刚好匹配

    int i(1);
    print(i);
    print(&i);

    const int i2(2);
    print(i2);
    print(&i2);

    char d('d');
    print<char, char>(d);    //调用4 函数模板重载

    return 0;
}
