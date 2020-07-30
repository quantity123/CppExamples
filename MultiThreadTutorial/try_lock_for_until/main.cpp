#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

timed_mutex mtx;

void fireworks()
{
    while (!mtx.try_lock_for(chrono::milliseconds(50))) //线程阻塞50毫秒以内都一直尝试拿到互斥锁，其中一个线程拿到后睡眠1秒，后面其它线程在一秒内上锁失败全进入循环打印"-"，直到拿到互斥锁的线程让出锁。
    {
        cout << "-";
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "*\n";
    mtx.unlock();
}

int main()
{
    thread threads[10];
    for (int i=0; i<10; ++i)
    {
        threads[i] = thread(fireworks);
    }
    for (auto& th: threads)
        th.join();
    return 0;
}
