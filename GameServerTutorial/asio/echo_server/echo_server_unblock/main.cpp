#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

enum {maxLength=1024};

class Session: public enable_shared_from_this<Session>
{
private:
    tcp::socket mSocket;
    char mData[maxLength];
    void doRead();
    void doWrite(size_t length);
public:
    Session(tcp::socket socket);
    void start();
};

void Session::doRead()
{
    auto self(shared_from_this());
    auto lbdDoWrite = [this, self](boost::system::error_code ec, size_t lenght)
    {
        if (!ec)
        {
            doWrite(lenght);
        }
    };
    mSocket.async_read_some(boost::asio::buffer(mData, maxLength), lbdDoWrite);
}

void Session::doWrite(size_t length)
{
    auto self(shared_from_this());
    auto lbdDoRead = [this, self](boost::system::error_code ec, size_t)
    {
        if (!ec)
        {
            doRead();
        }
    };
    mSocket.async_write_some(boost::asio::buffer(mData, length), lbdDoRead);
    //mSocket.async_send(boost::asio::buffer(mData, length), lbdDoRead);
    //boost::asio::async_write(mSocket, boost::asio::buffer(mData, length), lbdDoRead);
}

Session::Session(tcp::socket socket)
    : mSocket(move(socket))
{
}

void Session::start()
{
    doRead();
}

class Server
{
private:
    tcp::acceptor mAcceptor;
    tcp::socket mSocket;
    void doAccept();
public:
    Server(io_service& aIoService, short aPort);
    void start();
};

void Server::doAccept()
{
    auto lbdSessionStart = [this](boost::system::error_code ec)
    {
        if (!ec)
        {
            auto SharedPtrSession = make_shared<Session>(move(mSocket));   //move(m_socket)后，m_socket成初始化状态
            SharedPtrSession->start();
        }
        doAccept();
    };
    mAcceptor.async_accept(mSocket, lbdSessionStart);
}

Server::Server(io_service& aIoService, short aPort)
    : mAcceptor(aIoService, tcp::endpoint(tcp::v4(), aPort)), mSocket(aIoService) //tcp::v4默认相当于0.0.0.0
{
}

void Server::start()
{
    doAccept();
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            cerr << "Usage: async_tcp_echo_server<post>" << endl;
            return 1;
        }
        io_service ioService;
        Server server(ioService, atoi(argv[1]));
        server.start();
        ioService.run();
    } catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
