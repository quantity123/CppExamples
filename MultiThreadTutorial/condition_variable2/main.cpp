#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int cargo = 0;

bool shipment_available()
{
    return cargo != 0;
}

//消费者线程
void consume(int n)
{
    for (int i=0; i<n; ++i)
    {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, shipment_available);   //shipment_available 为假(==0)时候，wait一直阻塞当前线程，其它线程notify_*通知后shipment_available 为真(!=0)才会解除阻塞
        cout << cargo << endl;
        cargo = 0;
    }
}

int main()
{
    thread consumer_thread(consume, 10); //消费者线程

    //主线程为生产者线程，生产10个物品
    for (int i=0; i<10; ++i)
    {
        while (shipment_available())    //如果cargo不等于0，那么当前线程一直死循环
        {
            this_thread::yield();
        }
        unique_lock<mutex> lck(mtx);  //主线程与子线程都要操作cargo变量，所以线程之间用mutex互斥量隔开执行
        cargo = i + 1;
        cv.notify_one();
    }

    consumer_thread.join();
    return 0;
}
