#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cmath>

using namespace std;

class Root
{
public:
    double operator()(double x)
    {
        return sqrt(x); //开方
    }
};

int main()
{
    double data[]{4, 9, 16, 25, 36};
    Root root;

    cout << "Square roots are:" << endl;
    transform(begin(data), end(data), ostream_iterator<double>(cout, " "), root);   //把类改造操作符成函数
    cout << endl;

    cout << "Cubes are:" << endl;
    transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [](double x){return x*x*x;});    //lambda函数
    cout << endl;

    function<double(double)> op([](double x){return x*x;}); //用函数模板类型声明定义变量并初始化一个lambda函数
    cout << "Squares are:" << endl;
    transform(begin(data), end(data), ostream_iterator<double>(cout, " "), op);
    cout << endl;

    cout << "4th powers are:" << endl;
    transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [&op](double x){return op(x) * op(x);});   //lambda函数调用lambda函数
    cout << endl;

    //练习题1
    for(auto iter = begin(data); iter != end(data); ++iter)
    {
        cout << *iter << endl;
    }

    auto lbd1(
        [](double&)
        {
            return '*';
        }
    );
    transform(begin(data), end(data), ostream_iterator<char>(cout, "\n"), lbd1);

    return 0;
}
