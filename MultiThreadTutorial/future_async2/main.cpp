#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <chrono>
#include <future>

using namespace std;

double ThreadTask(int n)
{
    cout << "thread_id " << this_thread::get_id() << " start computing..." << endl;
    double ret = 0;
    for (int i=0; i<=n; i++)
    {
        ret += sin(i);
    }
    cout << "thread_id " << this_thread::get_id() << " finished computing..." << endl;
    return ret;
}

int main()
{
    future<double> fut(async(launch::async, ThreadTask, 100000000));
    //future<double> fut = async(launch::async, ThreadTask, 100000000);
#if 0
    auto t = fut.wait_until(chrono::system_clock::now() + chrono::seconds(1));
    while (t != future_status::ready)
    {
        cout << "task is running..." << endl;
    }
#else
    while (fut.wait_for(chrono::seconds(1)) != future_status::ready)
    {
        cout << "task is running..." << endl;
    }
#endif
    cout << fut.get() << endl;
    return 0;
}
