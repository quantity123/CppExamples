#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_fifty(char c)
{
    unique_lock<mutex> lck;
    lck = unique_lock<mutex>(mtx);  //把mtx管理的mutex互斥量移动赋值给新的lock对象
    for (int i=0; i<50; ++i)
    {
        cout << c;
    }
    cout << endl;
}

int main()
{
    thread th1(print_fifty, '*');
    thread th2(print_fifty, '$');
    th1.join();
    th2.join();
    return 0;
}
