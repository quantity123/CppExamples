#include <iostream>
#include <cstdlib>
#include <cstring>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::io_service;
using boost::asio::ip::tcp;

enum {maxLength=1024};

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            cerr << "Usage: main <host> <port>" << endl;
            return 1;
        }
        io_service ioService;
        tcp::resolver resolver(ioService);
        auto resolveResult = resolver.resolve({argv[1], argv[2]});
        tcp::socket socket(ioService);
        boost::asio::connect(socket, resolveResult);

        cout << "Enter Message Send to Server: ";
        char request[maxLength];
        cin.getline(request, maxLength);
        size_t requestLen = strlen(request);
        boost::asio::write(socket, boost::asio::buffer(request, requestLen));

        char reply[maxLength];
        size_t replyLen = boost::asio::read(socket, boost::asio::buffer(reply, requestLen));
        cout << "Server Reply is: ";
        cout.write(reply, replyLen);
        cout << endl;
    } catch (exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
