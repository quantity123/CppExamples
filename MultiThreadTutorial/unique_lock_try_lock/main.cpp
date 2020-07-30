#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_star()
{
    unique_lock<mutex> lck(mtx, defer_lock);
    if (lck.try_lock())
        cout << '*';
    else
        cout << 'X';    //如果打印出了X，那么try_lock锁线程失败返回false，try_lock是不阻塞等待的，锁线程成功则返回true
}

int main()
{
    vector<thread> threads;
    for (int i=0; i<500; ++i)
    {
        threads.emplace_back(print_star);   //这样放置一个vector成员就是创建一个线程
    }
    for (auto& x: threads)
    {
        x.join();
    }
    return 0;
}
