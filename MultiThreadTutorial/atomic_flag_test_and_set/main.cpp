#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

atomic<bool> ready(false);
atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int id)
{
    while (!ready)
    {
        this_thread::yield();
    }
    for (int i=0; i<1000000; ++i)   //哪个线程先执行完毕可以往后执行
    {
    }
    if (!winner.test_and_set())  //首次线程设置返回false，后面的线程设置返回true
    {
        cout << "thread #" << id << " won!" << endl;
    }
}

int main()
{
    vector<thread> threads;
    cout << "spawning 10 threads that count to 1 million..." << endl;
    for (int i=1; i<=10; ++i)
    {
        threads.emplace_back(thread(count1m, i));
    }
    ready = true;
    for (auto& th: threads)
    {
        th.join();
    }
    return 0;
}
