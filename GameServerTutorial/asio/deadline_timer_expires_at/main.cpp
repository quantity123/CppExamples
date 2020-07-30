#include <iostream>
#include <boost/asio.hpp>
//#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost;

void print(const system::error_code&, asio::deadline_timer* a_pTime, int* a_pCount)
{
    if (*a_pCount < 5)
    {
        cout << *a_pCount << endl;
        ++(*a_pCount);
        auto currTime = a_pTime->expires_at();  //获取当前实效时间
        a_pTime->expires_at(currTime + posix_time::seconds(1)); //重新指定一个时间
        //auto waitHandle = bind(print, asio::placeholders::error, a_pTime, a_pCount);    //绑定函数和函数的参数并返回一个等待句柄
        auto lambdaFunc = [a_pTime, a_pCount](const system::error_code& err)
        {
            print(err, a_pTime, a_pCount);
        };
        a_pTime->async_wait(lambdaFunc);
    }
}

int main()
{
    asio::io_service io;
    int count = 0;
    asio::deadline_timer dlt(io, posix_time::seconds(1));
    //auto waitHandle = bind(print, asio::placeholders::error, &dlt, &count);    //绑定函数和函数的参数并返回一个等待句柄
    auto lambdaFunc = [&dlt, &count](const system::error_code& err)
    {
        print(err, &dlt, &count);
    };
    dlt.async_wait(lambdaFunc);
    io.run();
    return 0;
}
