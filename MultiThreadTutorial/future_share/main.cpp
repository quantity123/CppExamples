#include <iostream>
#include <future>

int do_get_value()
{
    return 10;
}

using namespace std;

int main()
{
    //shared_future<int> sha_fut //单独用也可以
    future<int> fut = async(do_get_value);
    /*
    if (fut.valid())
        cout << "future1 value: " << fut.get() << endl;
    if (fut.valid())    //由于前面fut.get获取了值或异常，所以这里也是invalid
        cout << "future2 value: " << fut.get() << endl;
    */
    shared_future<int> sha_fut = fut.share();
    if (fut.valid())    //fut对象本身已经不和任何共享状态(async)关联，因此future状态不再是valid了
        cout << "future3 value: " << fut.get() << endl;
    if (sha_fut.valid())
        cout << "shared_future value: " << sha_fut.get() << endl;
    return 0;
}
