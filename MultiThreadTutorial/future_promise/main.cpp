#include <iostream>
#include <functional>
#include <thread>
#include <future>

using namespace std;

void print_int(future<int>& fut)
{
    int x = fut.get();  //future异步的返回promise里提供的值,如果prom没有set_value那么这里会阻塞
    cout << "value: " << x << endl;
}

promise<int> glo_prom;

void print_global_promise()
{
    future<int> fut = glo_prom.get_future();
    int x = fut.get();
    cout << "value: " << x << endl;
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();    //把promise与future关联起来可以线程同步共享状态值
    thread th(print_int, ref(fut));  //把future送入线程
    prom.set_value(100);    //promise保存一个值让future读取，future在另一个线程读取就作到了线程同步共享值,设置成功后标志为ready才能让future获取值
    th.join();

    glo_prom = promise<int>();  //glo_prom被move赋值成一个新promise对象
    thread th2(print_global_promise);
    glo_prom.set_value(200);
    th2.join();
    return 0;
}
