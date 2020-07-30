#include <iostream>

using namespace std;

class Object
{
public:
    explicit Object(int a)
    {
        m_value = new int;
        *m_value = a;
    }
    ~Object()
    {
        delete m_value;
    }
private:
    int* m_value;
};

class Evil
{
public:
    Evil()
    {
        throw 10;
    }
    ~Evil() {}
};

class Normal: public Object
{
public:
    explicit Normal(int a): Object(a), m_a(a+1), m_resource(new int(a+2)), m_evil()
    {

    }
    ~Normal()
    {
        delete m_resource;
    }
private:
    Object m_a;
    int* m_resource;
    Evil m_evil;
};

int main()
{
    Normal n(1);
    return 0;
}
