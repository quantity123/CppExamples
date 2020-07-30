#include <iostream>

using namespace std;

struct A
{
    double x;
};

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b)
{
    return a + b; //返回推导的值
    //return (a + b) //返回推导的值的引用&
}
/*  C++14 可以下面这样写，不需要 -> decltype
auto add(T a, U b)
{
    return a + b;
}
*/

int main()
{
    const A* a = new A{0};

    decltype(a->x) y;
    auto& yy = y;
    //double& yy = y;
    cout << yy << endl;

    decltype ((a->x)) z = y;
    cout << z << endl;



    auto c = add(1.0, 3);
    cout << c << endl;
    return 0;
}
