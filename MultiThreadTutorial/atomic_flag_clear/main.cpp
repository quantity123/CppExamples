#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;

atomic_flag lock_stream = ATOMIC_FLAG_INIT;
stringstream stream;

void append_number(int x)
{
    while (lock_stream.test_and_set())
    {
    }
    stream << "thread #" << x << endl;
    lock_stream.clear();    //清除test_and_set的标志位，即下次调用test_and_set返回false
}

int main()
{
    vector<thread> threads;
    for (int i=0; i<=10; ++i)
    {
        threads.emplace_back(thread(append_number, i));
    }
    for (auto& t: threads)
    {
        t.join();
    }
    cout << stream.str() << endl;
    return 0;
}
