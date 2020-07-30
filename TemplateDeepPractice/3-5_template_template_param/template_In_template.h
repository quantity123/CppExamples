#ifndef TEMPLATE_IN_TEMPLATE_H
#define TEMPLATE_IN_TEMPLATE_H
#include <iostream>

template
<
        typename T, //如果把这个类型定义放到末尾，可以不指定，由第一个参数来推导
        template<typename TT>
        class Func //类作为模板参数,TT是类的模板类型，可以传入Func类里面使用
>
void foreach(T array[], unsigned int size)
{
    Func<T> func;   //把T作为类型当作模板TT类型
    for (unsigned int i=0; i<size; ++i)
    {
        func(array[i]);
    }
}

template<typename T>
class inc
{
public:
    void operator()(T& v) const
    {
        ++v;
    }
};

template<typename T>
class cdec
{
public:
    void operator()(T& v) const
    {
        --v;
    }
};

template<typename T>
class print
{
public:
    void operator()(T& v) const
    {
        std::cout << " " << v;
    }
};
#endif // TEMPLATE_IN_TEMPLATE_H
