#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex foo, bar;

void task_a()
{
    lock(foo, bar);
    unique_lock<mutex> lck1(foo, adopt_lock); //adopt_lock参数意思是锁对象被创建后并不立即锁互斥量，因为这个互斥量前面必须已经被lock了，否则报错
    unique_lock<mutex> lck2(bar, adopt_lock);
    cout << "task a" << endl;
}

void task_b()
{
    //foo.lock();
    //bar.lock();
    unique_lock<mutex> lck1, lck2;
    lck1 = unique_lock<mutex>(foo, defer_lock); //defer_lock前提是你不能自己先lock，否则会报异常，初始化一个没有加锁的互斥量
    lck2 = unique_lock<mutex>(bar, defer_lock);
    lock(lck1, lck2);
    cout << "task b" << endl;
}

int main()
{
    thread th1(task_a);
    thread th2(task_b);
    th1.join();
    th2.join();
    return 0;
}
