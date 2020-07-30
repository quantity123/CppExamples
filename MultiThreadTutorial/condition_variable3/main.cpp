#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
//condition_variable cv;    //使用这个有bug
int cargo = 0;

//消费者线程
void consumer()
{
    unique_lock<mutex> lck(mtx);
    //while (cargo == 0)
      //  cv.wait(lck);
    cout << "product ID: " << cargo << endl;
    //cargo = 0;
}

//生产者线程
void producer()
{
    unique_lock<mutex> lck(mtx);
    ++cargo;
    //cv.notify_one();
}

int main()
{
    thread consumers[10], producers[10];
    for (int i=0; i<10; ++i)
    {
        consumers[i] = thread(consumer);
        producers[i] = thread(producer);
    }
    for (int i=0; i<10; ++i)
    {
        consumers[i].join();
        producers[i].join();
    }
    return 0;
}
