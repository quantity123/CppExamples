#include <iostream>

using namespace std;

void functionPrint(int a, int b, int c)
{
    cout << "a=" << a << " b=" << b << " c=" << c << endl;
}

template<typename T1, typename T2, typename T3>
void templatePrint(T1 a, T2 b, T3 c)
{
    cout << "a=" << a << " b=" << b << " c=" << c << endl;
}

struct StructPrint
{
    void operator()(int a, int b, int c) const
    {
        cout << "a=" << a << " b=" << b << " c=" << c << endl;
    }
};

struct StructTemplatePrint
{
    template<typename T1, typename T2, typename T3>
    void operator()(T1 a, T2 b, T3 c) const
    {
        cout << "a=" << a << " b=" << b << " c=" << c << endl;
    }
};

template<typename Func>
void lambdaTemplateFunc(Func func, int a, int b, int c)
{
    func(a, b, c);
}

int main()
{
    StructPrint structPrint;
    StructTemplatePrint structTemplatePrint;

    functionPrint(1, 2, 3);
    templatePrint(2, 3, 4);
    templatePrint(2.22, 3.33, 4.44);
    structPrint(3, 4, 5);
    structTemplatePrint(4, 5, 6);
    structTemplatePrint(4.44, 5.55, 6.66);

    //lambda function
    auto func1 = [](int a, int b, int c)
    {
        cout << "a=" << a << " b=" << b << " c=" << c << endl;
    };
    func1(5, 6, 7);		//由小括号定义lambda函数，所以调用时候要传实参
    lambdaTemplateFunc(func1, 6, 7, 8);

    int a = 7;
    int b = 8;
    int c = 9;
    auto func2 = /*[&a, &b, &c]传参可以引用方式也可以拷贝方式*/ /*[=]全拷贝方式传参*/ [&]/*全引用方式传参*/ /*如果中括号传参()小括号可要可不要*/
    {
        cout << "a=" << a << " b=" << b << " c=" << c << endl;
    };
    func2();    //由中括号固定变量传实参的方式定义lambda函数，所以调用时候就没有实参
    return 0;
}
