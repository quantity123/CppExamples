#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int count = 0;

void print_count_and_unlock(mutex* p_mtx)
{
    cout << "count: " << count << endl;
    p_mtx->unlock();    //这里要解锁，因为lck已经不管理了，不能自动解锁互斥量，所以要手动解锁
}

void task()
{
    unique_lock<mutex> lck(mtx, try_to_lock);

    cout << lck.mutex()->native_handle() << endl;   //lck.mutex是返回lck对象管理的mtx指针

    ++count;

    if (lck.owns_lock())
        cout << "* ";
    else
        cout << "X ";

    auto p_mtx = lck.release();
    print_count_and_unlock(p_mtx);
    //lck.unlock(); //lck变量已release把互斥量所有权释放，在解锁就报异常了。
}

int main()
{
    cout << mtx.native_handle() << endl;
    vector<thread> threads;
    for (int i=0; i<10; ++i)
    {
        threads.emplace_back(task);
    }
    for (auto& x: threads)
    {
        x.join();
    }
    return 0;
}
