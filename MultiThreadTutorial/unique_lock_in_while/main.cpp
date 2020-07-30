#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;

void test_mutex_inWhile()
{
    int i = 0;
    while (1)
    {
        unique_lock<mutex> lock(mtx);   //如果下面有条件变量condition_variable.wait，那么线程第一次会在这里阻塞，否则线程按传统阻塞
        cout << "threadID: " << this_thread::get_id() << endl;
        cv.wait(lock);  //线程进入wait过一次后面就不会在上面 unique_lock<mutex> lock(mtx); 代码处阻塞直接到条件wait这里阻塞
        //mtx.lock();
        cout << "threadID: " << this_thread::get_id() << endl;
        //++i;

        //lock.unlock();
        //mtx.unlock();
    }
}

void test_notify_all()
{
    cv.notify_all();
}

int main()
{
    thread th1(test_mutex_inWhile);
    thread th2(test_mutex_inWhile);
    thread th3(test_notify_all);
    th1.join();
    th2.join();
    th3.join();
    return 0;
}
