#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time.hpp>
#include <boost/asio/steady_timer.hpp>

using namespace std;
using namespace boost;

void callback_1(const system::error_code&)
{
    cout << "async_wait_1" << endl;
}

void callback_2(const system::error_code&)
{
    cout << "async_wait_2" << endl;
}

int main()
{
    asio::io_service io;
    asio::deadline_timer t0(io, posix_time::seconds(2));
    asio::deadline_timer t1(io, posix_time::seconds(5));
    asio::deadline_timer t2(io, posix_time::seconds(3));
    asio::steady_timer t3(io);

    t0.wait();   //阻塞等待2秒
    cout << "date_time_sync_wait" << endl;
    t1.async_wait(callback_1); //非阻塞等待
    t2.async_wait(callback_2);
    io.run();   //io_service启动timer并调用所有的callback

    t3.expires_from_now(chrono::seconds(2));
    t3.wait();//阻塞等待2秒
    cout << "steady_timer_wait" << endl;
    return 0;
}
