#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

using namespace std;

template<typename T>
class Lock
{
public:
    ~Lock()
    {
        mMutex.unlock();
    }
    Lock(T& mutex): mMutex{mutex}
    {
        mMutex.lock();
    }
private:
    T& mMutex;
};
using MutexLock = Lock<mutex>;

class Counter
{
public:
    void incCount();
    int getCount() const;
    Counter();
private:
    //atomic<int> mCount;   //原子类型多线程操作不会混乱
    //atomic_int mCount;  //和上面一样的，这类型是已经定义过的
    int mCount;             //使用mutex来加锁解锁
    mutex mMutex;
};

Counter::Counter()
{
    mCount = 0;
}

int Counter::getCount() const
{
    return mCount;
}

void Counter::incCount()
{
    //MutexLock mtLock{mMutex};
    lock_guard<mutex> mtLock{mMutex/*, adopt_lock*/};   //adopt_lock参数是告诉mtLock在构造时候不创造临界区
    //mMutex.lock();
    ++mCount;
    //mMutex.unlock();
}

int work(int a)
{
    return a + a;
}

template <class Iter>
void realWork(Counter& c, double& totalValue, Iter b, Iter e)
{
    for (; b != e; ++b)
    {
        totalValue += work(*b);
        c.incCount();
    }
}

class ThreadGuard
{
public:
    ~ThreadGuard()
    {
        if (mThread.joinable())
            mThread.join();
    }
    ThreadGuard(thread& t): mThread{t}
    {
    }
private:
    thread& mThread;
};

int main()
{
    unsigned n = thread::hardware_concurrency();
    cout << n << " threads are supported." << endl;

    vector<int> vec;
    for (int i=0; i<10000000; ++i)
    {
        vec.push_back(rand() % 100);
    }
    double totalValue{0.0};
    Counter counter;
    realWork(counter, totalValue, vec.begin(), vec.end());
    cout << "single thread total times: " << counter.getCount() << " " << totalValue << endl;




    auto oneThird = vec.begin() + (vec.size()/3);
    auto twoThird = vec.begin() + (vec.size()/3*2);

    double totalValue2 = 0.0;
    Counter counter2;
    auto oneThirdThreadFunc = [&counter2, &totalValue2, oneThird, twoThird]
    {
        realWork(counter2, totalValue2, oneThird, twoThird);
    };
    thread oneThirdThread{oneThirdThreadFunc};
    ThreadGuard tg{oneThirdThread}; //用这个类自动管理释放，主线程后面就不用调用join函数等待

    double totalValue3 = 0.0;
    //Counter counter3;
    auto end = vec.end();
    auto twoThirdThreadFunc = [&counter2, &totalValue3, twoThird, end]
    {
        realWork(counter2, totalValue3, twoThird, end);
    };
    thread twoThirdThread{twoThirdThreadFunc};
    twoThirdThread.detach();    //系统将自动回收线程资源，主线程无需join等待子线程执行结束，作服务器开发尽量不用，自己用join管理线程

    double totalValue4 = 0.0;
    //Counter counter4;
    realWork(counter2, totalValue4, vec.begin(), oneThird);

    if (oneThirdThread.joinable())  //如果使用了ThreadGuard类这里可以无需判断，但是主线程提前退出后导致线程2提前中断退出，最终输出结果不正确
        oneThirdThread.join();

    if (twoThirdThread.joinable())  //如果前面调用了detach()函数，那么这里判断为False
        twoThirdThread.join();      //如果前面调用了detach()函数，那么这里执行报错

    /*
    //1.如果没有必要的情况下，线程间不要共享资源
    auto totalCount = counter2.getCount() + counter3.getCount() + counter4.getCount();
    totalValue = totalValue2 + totalValue3 + totalValue4;
    cout << "multithread total times: " << totalCount << " " << totalValue << endl;
    */

    //2.使用原子类型mCount
    auto totalCount = counter2.getCount();
    totalValue = totalValue2 + totalValue3 + totalValue4;
    cout << "multithread total times: " << totalCount << " " << totalValue << endl;

    return 0;
}
