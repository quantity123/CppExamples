#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <exception>

using namespace std;

void get_int(promise<int>& prom)
{
    int x;
    cout << "enter an integer value: ";
    cin.exceptions(ios::failbit);   //输入错误抛异常
    try
    {
        cin >> x;
        prom.set_value(x);
    } catch (exception&)
    {
        prom.set_exception(current_exception());    //给promise设置异常值
    }
}

void print_int(future<int>& fut)
{
    try
    {
        int x = fut.get();
        cout << "value: " << x << endl;
    } catch (exception& e)
    {
        cout << "exception caught: " << e.what() << endl;
    }
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread th1(get_int, ref(prom));
    thread th2(print_int, ref(fut));
    th1.join();
    th2.join();
    return 0;
}
