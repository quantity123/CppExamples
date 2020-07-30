#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

using namespace std;

mutex mt;
atomic_bool ready{false};

void worker(int i)
{
    while (!ready)
    {
        //this_thread::yield()  //这个方法是让出线程占用cpu
        this_thread::sleep_for(chrono::seconds(1)); //停一秒检查一次条件可以减少cpu使用率
    }
    lock_guard<mutex> lock(mt);
    cout << "hello world " << i << endl;
}

int main()
{
    const auto threadCount = 4;
    vector<thread> threadPool;
    for (int i=0; i<threadCount; ++i)
    {
        threadPool.emplace_back(worker, i);
    }
    this_thread::sleep_for(chrono::seconds(5));
    ready = true;
    for (auto &v: threadPool)
    {
        if (v.joinable())
            v.join();
    }
    cout << "threadPool finish!" << endl;
    return 0;
}
