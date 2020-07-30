#include <iostream>
#include <future>
#include <chrono>

using namespace std;

bool is_prime(int x)
{
    for (int i=2; i<x; ++i)
    {
        if (x%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    future<bool> fut = async(is_prime, 4);
    cout << "checking, please wait...";
    fut.wait(); //如果async共享状态的标志位不是ready，wait函数会阻塞当前主线程
    cout << "\n4 ";
    chrono::milliseconds span(100);
    while (fut.wait_for(span) == future_status::timeout)    //wait_for函数在设置的时间段结束之前async共享状态标志位没有成为ready，那么线程阻塞，否则超过设置的时间段则返回
        cout << '.';
    bool x = fut.get();
    cout << (x ? "is" : "is not") << " prime." << endl;
    return 0;
}
