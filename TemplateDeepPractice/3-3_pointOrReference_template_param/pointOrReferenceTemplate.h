#ifndef POINTORREFERENCETEMPLATE_H
#define POINTORREFERENCETEMPLATE_H
template<int* p>
class wrapper
{
public:
    void set(int& v)
    {
        *p = v; //实际是给下面 global_v 赋值
    }
    int get()
    {
        return *p;  //实际是获取下面 global_v 赋值
    }
};

template<int& p>
class wrapper2
{
public:
    void set(int& v)
    {
        p = v;
    }
    int get()
    {
        return p;
    }
};

int global_v = 0;

#endif // POINTORREFERENCETEMPLATE_H
