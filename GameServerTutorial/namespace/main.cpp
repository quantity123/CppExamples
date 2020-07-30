#include <iostream>

using namespace std;

namespace XGroup
{
    class A
    {
        int value;
    };
}

namespace YGroup
{
    class A
    {
        int value;
    };
    class B
    {

    };
}

class A
{
    int value;
};

void testNamespace1()
{
    XGroup::A a;
    YGroup::A b;
    ::A c;
}

void testNamespace2()
{
    namespace ZGroup = XGroup;  //命名空间可以声明一个变量
    ZGroup::A a;

    using YGroup::B;    //先声明出命名空间里的类再使用
    B b;

    YGroup::A aa;   //直接使用命名空间里的类
}

using namespace YGroup;

int main()
{
    A a;    //会有冲突，因为声明了YGroup这个命名空间里所有成员，但是YGroup::A 与 外部的一个 A 类冲突了
    B b;
    return 0;
}
