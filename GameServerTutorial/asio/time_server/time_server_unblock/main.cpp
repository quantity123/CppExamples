#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <functional>

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

class TCPConnection;
using SharedPtrTCPConnection = shared_ptr<TCPConnection>;
class TCPConnection: public enable_shared_from_this<TCPConnection>
{
private:
    tcp::socket mSocket;
    string mMsg;
    TCPConnection(io_service& io_service);
    void handleWrite(const boost::system::error_code&, size_t);
public:
    static SharedPtrTCPConnection create(io_service& io_service);
    tcp::socket& getSocket();
    void start();
};

string makeDayTimeString()
{
    time_t now = time(nullptr);
    return ctime(&now);
}

TCPConnection::TCPConnection(io_service& io_service)
    : mSocket(io_service)
{
}

void TCPConnection::handleWrite(const boost::system::error_code&, size_t)
{
}

SharedPtrTCPConnection TCPConnection::create(io_service& io_service)
{
    //return make_shared<TCPConnection>(io_service);
    return (SharedPtrTCPConnection)new TCPConnection(io_service);
}

tcp::socket& TCPConnection::getSocket()
{
    return mSocket;
}

void TCPConnection::start()
{
    mMsg = makeDayTimeString();
    auto self = shared_from_this();
    auto writeHandler = [self=move(self)](auto err, auto bytes_transferred)
    {
        self->handleWrite(err, bytes_transferred);
    };
    boost::asio::async_write(mSocket, boost::asio::buffer(mMsg), writeHandler);
}

class TCPServer
{
private:
    tcp::acceptor mAcceptor;
    void startAccept();
    void handleAccept(SharedPtrTCPConnection newConnection, const boost::system::error_code& err);
public:
    TCPServer(io_service& io_service);
};

void TCPServer::startAccept()
{
    auto newConnection = TCPConnection::create(mAcceptor.get_io_service());
    auto acceptHandler = [this, newConnection](auto err)
    {
        this->handleAccept(newConnection, err);
    };
    mAcceptor.async_accept(newConnection->getSocket(), acceptHandler);
}

void TCPServer::handleAccept(SharedPtrTCPConnection newConnection, const boost::system::error_code& err)
{
    if (!err)
    {
        newConnection->start();
    }
    startAccept();
}

TCPServer::TCPServer(io_service& io_service)
    : mAcceptor(io_service, tcp::endpoint(tcp::v4(), 3000))
{
    startAccept();
}

int main()
{
    try
    {
        io_service ioService;
        TCPServer tcpServer(ioService);
        ioService.run();
    } catch (exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
