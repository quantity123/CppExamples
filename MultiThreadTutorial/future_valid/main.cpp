#include <iostream>
#include <future>
#include <utility>

using namespace std;

int do_get_value()
{
    return 22;
}

int main()
{
    future<int> foo, bar;
    foo = async(do_get_value);
    //bar = move(foo);    //move赋值，bar为valid, foo为invalid
    if (foo.valid())
        cout << "foo value: " << foo.get() << endl;
    else
        cout << "foo is not valid" << endl;
    if (bar.valid())
        cout << "bar value: " << bar.get() << endl;
    else
        cout << "bar is not valid" << endl;

    if (foo.valid())    //由于前面代码foo.get获取过一次值，所以这里foo也成为invalid
        cout << "foo value: " << foo.get() << endl;
    else
        cout << "foo is not valid" << endl;
    if (bar.valid())
        cout << "bar value: " << bar.get() << endl;
    else
        cout << "bar is not valid" << endl;
    return 0;
}
