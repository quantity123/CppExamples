#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

void thread_task(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout << "hello thread " << this_thread::get_id() << " paused " << n << " seconds" << endl;
}

int main()
{
    thread threads[5];
    cout << "Spawing 5 threads...\n";
    for (int i=0; i<5; ++i)
    {
        threads[i] = thread(thread_task, i+1);
    }
    cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads)
    {
        t.join();
    }
    cout << "All threads joined." << endl;
    return 0;
}
