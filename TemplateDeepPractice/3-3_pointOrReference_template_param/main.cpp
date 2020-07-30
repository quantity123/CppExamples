#include <iostream>
#include "pointOrReferenceTemplate.h"

using namespace std;

int main()
{
    wrapper<&global_v> gWrapper;
    int i(10);
    gWrapper.set(i);
    cout << gWrapper.get() << endl;

    int i2(20);
    wrapper2<global_v> gWrapper2;
    gWrapper2.set(i2);
    cout << gWrapper2.get() << endl;

    //int local_v;  //报错，因为局部变量引用或者指针不可用于模板参数
    static int local_v; //静态变量属于全局变量所以可以作为类模板参数，还有类static变量，extern外部变量都可以
    int i3(30);
    wrapper2<local_v> gWrapper3;
    gWrapper3.set(i3);
    cout << gWrapper3.get() << endl;
    return 0;
}
