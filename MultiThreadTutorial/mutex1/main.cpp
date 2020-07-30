#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

volatile int counter(0);

mutex mtx;

void attempt_10k_increases()
{
    for (int i=0; i<1000; ++i)
    {
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}

int main()
{
    thread threads[10];
    for (int i=0; i<10; ++i)
    {
        threads[i] = thread(attempt_10k_increases);
    }
    for (auto& th: threads)
    {
        th.join();
    }
    cout << counter << " successful increases of the counter." << endl;
    return 0;
}
