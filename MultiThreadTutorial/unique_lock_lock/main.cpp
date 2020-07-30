#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_thread_id(int id)
{
    unique_lock<mutex> lck(mtx, defer_lock);
    lck.lock();
    cout << "thread #" << id << endl;
    lck.unlock();
}

int main()
{
    thread threads[10];
    for (int i=0; i<10; ++i)
    {
        threads[i] = thread(print_thread_id, i+1);
    }
    for (auto& th: threads)
    {
        th.join();
    }
    return 0;
}
