#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

int packagedTask(int from, int to)
{
    for (int i=from; i!=to; --i)
    {
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Finished!\n";
    return from - to;
}

int test(int i)
{
    return i;
}

int compute_task(int x)
{
    return x * 2;
}

future<int> launcher_task3(packaged_task<int(int)>& task, int arg)
{
    if (task.valid())
    {
        future<int> ret = task.get_future();
        thread th3(move(task), arg);
        th3.detach();
        return ret;
    }
    else
    {
        future<int>();
    }
}

int main()
{
    packaged_task<int(int, int)> task(packagedTask);    //已经把线程任务函数定义到了这里
    future<int> ret = task.get_future();
    thread th(move(task), 10, 0);   //通过move函数把task任务移动到线程参数
    int value = ret.get();
    cout << "the packagedTask lasted for " << value << " seconds." << endl;
    th.join();

    packaged_task<int(int)> task2(test);
    future<int> ret2 = task2.get_future();
    thread th2(move(task2), 2);
    th2.detach();   //让线程th2分离主线程控制，自动释放，无需join
    int v = ret2.get();
    cout << "task2 value: " << v << endl;

    packaged_task<int(int)> task3(compute_task);
    future<int> ret3 = launcher_task3(task3, 33);
    cout << "the compute_task is: " << ret3.get() << endl;
    //由于线程调用了detach所以主线程无需join
    return 0;
}
