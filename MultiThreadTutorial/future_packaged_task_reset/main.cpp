#include <iostream>
#include <utility>
#include <future>
#include <thread>

using namespace std;

int triple(int x)
{
    return x * 3;
}

int main()
{
    packaged_task<int(int)> tsk(triple);

    future<int> fut = tsk.get_future();
    thread th1(ref(tsk), 100);
    //tsk(100);
    cout << "the triple of 100 is " << fut.get() << endl;

    tsk.reset();
    fut = tsk.get_future();
    //thread th2(ref(tsk), 200);
    tsk(200);
    cout << "the triple of 200 is " << fut.get() << endl;

    tsk.reset();
    fut = tsk.get_future();
    thread th3(move(tsk), 300);
    //tsk(300);
    //thread th3(ref(tsk), 300);
    cout << "the triple of 3 is " << fut.get() << endl;

    th1.join();
    //th2.join();
    th3.join();

    return 0;
}
