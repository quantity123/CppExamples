#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost;

class Printer
{
private:
    int m_count;
    asio::io_service::strand m_strand;  //strand这只正对io_service对象的线程同步保护
    asio::deadline_timer m_timer1;
    asio::deadline_timer m_timer2;
public:
    Printer(asio::io_service &io);
    ~Printer();
    void print1();
    void print2();
};

Printer::Printer(asio::io_service &io)
    : m_count(0), m_strand(io), m_timer1(io, posix_time::seconds(1)), m_timer2(io, posix_time::seconds(1))
{
    auto lbd_print1 = [this](const system::error_code&)
    {
        this->print1();
    };
    m_timer1.async_wait(m_strand.wrap(lbd_print1));
    auto lbd_print2 = [this](const system::error_code&)
    {
        this->print2();
    };
    m_timer2.async_wait(m_strand.wrap(lbd_print2));
}

Printer::~Printer()
{
    cout << "final count is " << m_count << endl;
}

void Printer::print1()
{
    if (m_count < 10)
    {
        cout << "timer 1: " << m_count << endl;
    }
    else
    {
        return;
    }
    ++m_count;
    m_timer1.expires_at(m_timer1.expires_at() + posix_time::seconds(1));
    auto lbd_print1 = [this](const system::error_code&)
    {
        this->print1();
    };
    m_timer1.async_wait(m_strand.wrap(lbd_print1));
    cout << m_count << "end" << endl;
}

void Printer::print2()
{
    if (m_count < 10)
    {
        cout << "timer 2: " << m_count << endl;
    }
    else
    {
        return;
    }
    ++m_count;
    m_timer2.expires_at(m_timer2.expires_at() + posix_time::seconds(1));
    auto lbd_print2 = [this](const system::error_code&)
    {
        this->print2();
    };
    m_timer2.async_wait(m_strand.wrap(lbd_print2));
    cout << m_count << "end" << endl;
}

int main()
{
    asio::io_service io;
    Printer p(io);
    auto ioRun = [&io]()
    {
        io.run();
    };
    thread t(ioRun);
    //io.post() //post可以把函数设定到 t 线程中运行
    t.join();
    return 0;
}
