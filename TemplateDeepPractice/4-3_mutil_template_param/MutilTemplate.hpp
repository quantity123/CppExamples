#ifndef MUTILTEMPLATE_HPP
#define MUTILTEMPLATE_HPP
#include <iostream>

template<typename T0, typename T1, typename T2>
struct S
{
    std::string id()
    {
        return "General";
    }
};

template<typename T0, typename T1>
struct S<T0, T1, char>
{
    std::string id()
    {
        return "Specialization 1";
    }
};

template<typename T0>
struct S<T0, char, char>
{
    std::string id()
    {
        return "Specialization 2";
    }
};

template<typename T>
struct S<int, T, T>
{
    std::string id()
    {
        return "Specialization 3";
    }
};
#endif // MUTILTEMPLATE_HPP
