#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int i)
{
    for (int cnt=0; cnt<100; ++cnt)
    {
        while (lock.test_and_set(memory_order_acquire))
        {
        }
        cout << "Output from thread = " << i << "，cnt = " << cnt << endl;
        lock.clear(memory_order_release);
    }
}

int main()
{
    vector<thread> threads;
    for (int i=0; i<10; ++i)
    {
        threads.emplace_back(thread(f, i));
    }
    for (auto& th: threads)
    {
        th.join();
    }
    return 0;
}
