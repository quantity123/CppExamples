#include <iostream>

using namespace std;

//模板可以前置声明，先声明后面实现，t0,t2加了默认类型后，函数的默认t1,t3,t4可以不用<>指定类型来调用函数
//template<typename T0 = float, typename T1, typename T2 = float, typename T3, typename T4>
//T0 func(T1 v1, T3 v3, T4 v4);

template<typename T0 = float, typename T1, typename T2 = float, typename T3, typename T4>
T0 func(T1 v1, T3 v3, T4 v4)
{
    static T0 sv0 = T0(0);
    static T2 sv2 = T2(0);
    cout << "\tv1: " << v1 << "\tv3: " << v3 << "\tv4: " << v4 << "\t|| sv0: " << sv0;
    T2 v2 = sv2;
    sv0 -= 1;
    sv2 -= 1;
    return v2;
}
