#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;  //全局条件变量
bool ready = false; //全局标志位

void do_print_id(int id)
{
    unique_lock<mutex> lck(mtx);    //当第一个线程进了后面线程都阻塞
    if (!ready)
    {
        cv.wait(lck);   //一个进来的线程会在这里阻塞等待，然后wait函数会调用lck.unlock释放锁，让其它线程继续跑，当主线程调用notify_*当前线程被唤醒
    }
    cout << "thread " << id << endl;
}

void go()
{
    unique_lock<mutex> lck(mtx);  //个人认为当前函数没有被多线程访问，所以无需使用线程锁互斥量
    ready = true;
    cv.notify_all();    //通知唤醒被condition_variable.wait函数阻塞的线程
}

int main()
{
    //thread threads[10];
    thread threads[1];
    //for (int i=0; i<10; i++)
    for (int i=0; i<1; i++)
        threads[i] = thread(do_print_id, i);
    cout << "10 threads ready to race..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    go();
    for (auto& th: threads)
        th.join();
    return 0;
}
