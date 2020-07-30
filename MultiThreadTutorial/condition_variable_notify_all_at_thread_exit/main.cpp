#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void print_id(int id)
{
    unique_lock<mutex> lck(mtx);
    if (!ready)
        cv.wait(lck);
    cout << "thread " << id << endl;
}

void go()
{
    unique_lock<mutex> lck(mtx);
    ready = true;
    notify_all_at_thread_exit(cv, move(lck));
}

int main()
{
    thread threads[10];
    for (int i=0; i<10; ++i)
    {
        threads[i] = thread(print_id, i);
    }
    cout << "10 threads ready to race..." << endl;
    thread th(go);
    //th.detach();
    for (auto& t: threads)
    {
        t.join();
    }
    th.join();
    return 0;
}
