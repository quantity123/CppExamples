#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

atomic<int> foo(0);
atomic_int foo1(0); //atomic_int类型就是atomic<int>

//生产者
void set_foo(int x)
{
    foo1 = x;    //调用 atomic::operator=()
    foo.store(30, memory_order_relaxed); //设置原子对象foo的值
}

//消费者
void print_foo()
{
    while (foo1 == 0)
    {
        this_thread::yield();
    }
    if (foo1.is_lock_free()) //is_lock_free特性是多个线程访问时，不会导致线程阻塞
    {
        cout << "foo1: " << foo1 << endl;
        cout << "foo1: " << static_cast<int>(foo1) << endl;
    }

    while (foo == 0)
    {
        this_thread::yield();
    }
    if (foo.is_lock_free())
    {
        //cout << "foo: " << foo << endl;
        int v = foo.load(memory_order_relaxed);
        cout << "foo: " << v << endl;
        int v1 = foo.exchange(600, memory_order_relaxed);
        cout << "exchange foo: " << foo << endl;
        cout << "return exchange foo: " << v1 << endl;
    }
}

int main()
{
    thread th1(print_foo);
    thread th2(set_foo, 20);
    th1.join();
    th2.join();
    return 0;
}
