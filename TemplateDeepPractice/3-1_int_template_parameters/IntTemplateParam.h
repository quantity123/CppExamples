#ifndef INTTEMPLATEPARAM_H
#define INTTEMPLATEPARAM_H

#include <stdexcept>

using namespace std;

template<typename T, unsigned int size>
class Array
{
private:
    T mElems[size];
public:
    T& operator[](unsigned int i)
    {
        if (i >= size)
            throw out_of_range("array access out of range.");   //抛异常
        else
            return mElems[i];
    }
};

#endif // INTTEMPLATEPARAM_H
