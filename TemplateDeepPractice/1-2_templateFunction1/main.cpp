#include "func.hpp"

using namespace std;

template<typename T>
const T& max_element(const T* l, unsigned int sz)
{
    const T* max_value(l);
    for (unsigned int i=1; i<sz; ++i)
    {
        if (l[i] > *max_value)
            max_value = &l[i];
    }
    return *max_value;
}

int main()
{
    int l[] = {2, 0, 5, 6}; //最大的数是 6
    char cl[] = "August";   //最大的字符是 u
 //   auto v1 = max_element<int>(l, 4);   //模板函数调用方式指定函数模板类型
    auto v1 = max_element(l, 4);   //模板函数调用方式可以根据参数l类型自动推导
 //   auto v2 = max_element<char>(cl, 6);	//模板函数调用方式指定函数模板类型
    auto v2 = max_element(cl, 6);
    cout << v1 << endl; //<int> 是模板指定类型
    cout << v2 << endl;   //<char> 是模板指定类型


    double sv2;
    //sv2 = func<double, int, int>(1, 2, 3);	//模板函数调用方式指定函数模板类型
    sv2 = func(1, 2, 3);
    cout << "\tsv2: " << sv2 << endl;
    //sv2 = func<double, int, int>(1, 2, 3);  //实参数不变那么函数里面static变量不初始化为0
    sv2 = func(1, 2, 3);
    cout << "\tsv2: " << sv2 << endl;
    //sv2 = func<double, int, int>(1, 0.1, 0.1);  //实参数变了static变量初始化为0
    sv2 = func(1, 0.1, 0.1);
    cout << "\tsv2: " << sv2 << endl;
    //sv2 = func<int, double, double>(0.1, 0.1, 0.1);
    sv2 = func(0.1, 0.1, 0.1);
    cout << "\tsv2: " << sv2 << endl;

    return 0;
}
