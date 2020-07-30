#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

string make_day_time_string()
{
    time_t now = time(nullptr);
    return ctime(&now);
}

int main()
{
    try
    {
        io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 3000));
        while (true)
        {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            string msg = make_day_time_string();
            boost::system::error_code err;
            boost::asio::write(socket, boost::asio::buffer(msg), err);
        }
    } catch (exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
