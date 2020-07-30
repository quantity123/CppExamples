#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
int value;

void do_read_value()
{
    cin >> value;
    cv.notify_one();
}

int main()
{
    cout << "Please, enter an integer:" << endl;
    thread th(do_read_value);
    mutex mtx;
    unique_lock<mutex> lck(mtx);
    while (cv.wait_for(lck, chrono::seconds(1)) == cv_status::timeout)
    {
        cout << '.';
        cout.flush();
    }
    cout << "your entered: " << value << endl;
    th.join();
    return 0;
}
