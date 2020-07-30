#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

void doPrintTen(char c, int ms)
{
    for (int i=0; i<10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(ms));
        cout << c;
    }
}

int main()
{
    cout << "launch::async:" << endl;
    future<void> foo = async(launch::async, doPrintTen, '*', 100);  //异步的启动线程在doPrintTen函数里执行
    future<void> bar = async(launch::async, doPrintTen, '$', 200);
    foo.get();
    bar.get();
    cout << endl << endl;

    cout << "launch::deferred:" << endl;
    foo = async(launch::deferred, doPrintTen, '*', 100);    //延迟调用，当共享状态值或异常被访问时调用，比如：访问共享状态foo.get()
    bar = async(launch::deferred, doPrintTen, '$', 200);
    bar.get();
    foo.get();
    cout << endl;
    return 0;
}
