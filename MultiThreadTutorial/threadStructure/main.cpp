#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

using namespace std;

void f1(int n)
{
    for (int i=0; i<5; ++i)
    {
        cout << "Thread " << n << " executing\n";
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

void f2(int& n)
{
    for (int i=0; i<5; ++i)
    {
        cout << "Thread 2 executing\n";
        ++n;
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

int main()
{
    int n = 0;

    thread t1;

    //thread t2(f1, n+1);

    thread t3(f2, ref(n));

    thread t4(move(t3));

    //t2.join();
    //t3.join();    //t3 ref函数不可被join，所以报错
    t4.join();

    cout << "Final value of n is " << n << endl;

    return 0;
}
