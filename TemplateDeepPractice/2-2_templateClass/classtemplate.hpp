#ifndef CLASSTEMPLATE_H
#define CLASSTEMPLATE_H

template<typename T0>
class ClassTemplate
{
public:
    T0 mV;
    template<typename T1>
    void set(const T1& v)
    {
        mV = T0(v);
    }
    template<typename T1>
    const T1 get() const;
};

template<typename T0> template<typename T1>
const T1 ClassTemplate<T0>::get() const
{
    return T1(mV);
}

#endif // CLASSTEMPLATE_H
