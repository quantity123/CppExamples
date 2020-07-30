#ifndef FUNCPOINTTEMPLATE_H
#define FUNCPOINTTEMPLATE_H
#include <iostream>

template<typename T, void (*f)(T& v)>   //模板第二个参数是函数f，f函数的参数是T类型的引用
void foreach(T array[], unsigned int size)
{
    for (unsigned int i=0; i<size; ++i)
    {
        f(array[i]);
    }
}

template<typename T>
void inc(T& v)
{
    ++v;
}

template<typename T>
void dec(T& v)
{
    --v;
}

template<typename T>
void print(T& v)
{
    std::cout << " " << v;
}
#endif // FUNCPOINTTEMPLATE_H
