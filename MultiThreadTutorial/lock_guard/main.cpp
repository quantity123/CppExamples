#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

using namespace std;

mutex mtx;

void print_even(int x)
{
    if (x%2 == 0)
        cout << x << " is event\n";
    else
        throw(logic_error("not even"));
}

void print_thread_id(int id)
{
    try
    {
        lock_guard<mutex> lck(mtx);
        print_even(id);
    } catch (logic_error&)
    {
        cout << "exception caught: " << id << " not even\n";
    }
}

int main()
{
    thread threads[10];
    for (int i=0; i<10; ++i)
    {
        threads[i] = thread(print_thread_id, i+1);
    }
    for (auto& th: threads)
        th.join();
    return 0;
}
