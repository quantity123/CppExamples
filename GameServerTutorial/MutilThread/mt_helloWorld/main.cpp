#include <iostream>
#include <thread>
//#include <chrono>

using namespace std;

void mutilThreadHelloWorld()
{
    cout << "mutilThread_HelloWorld" << endl;
}

int main()
{
    thread t(mutilThreadHelloWorld);    //子线程
    cout << "Hello World!" << endl;

    t.join();   //等待子线程执行完毕

    auto nowC = clock();
    this_thread::sleep_for(chrono::seconds(3)); //主线程睡3秒
    auto finishC = clock();
    cout << (finishC - nowC) << endl;

    //t.get_id() //获取子线程id
    //this_thread::get_id() //获取主线程id
    //thread::id() //线程id可以用作函数参数

    unsigned n = thread::hardware_concurrency();    //参考判断使用几个线程
    cout << n << endl;

    return 0;
}
