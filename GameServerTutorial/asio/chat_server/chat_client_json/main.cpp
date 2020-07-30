#include <cstdlib>
#include <cassert>
#include <iostream>
#include <deque>
#include <thread>
#include <boost/asio.hpp>
#include "../chat_message.h"
#include "../json_object.h"

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

using ChatMessageQueue = deque<ChatMessage>;

class ChatClient
{
public:
    ChatClient(io_service& ioService, tcp::resolver::iterator endPointIterator);
    void write(const ChatMessage& msg);
    void close();
private:
    io_service& mIoService;
    tcp::socket mSocket;
    ChatMessage mReadMsg;
    ChatMessageQueue mWriteMsgs;
    void doConnect(tcp::resolver::iterator endPointIterator);
    void doReadHeader();
    void doReadBody();
    void doWrite();
};

ChatClient::ChatClient(io_service& ioService, tcp::resolver::iterator endPointIterator)
    : mIoService(ioService), mSocket(ioService)
{
    doConnect(endPointIterator);
}

void ChatClient::write(const ChatMessage& msg)
{
    auto lbdCompletHandler = [this, msg]()
    {
        bool writeInProgress = !mWriteMsgs.empty();
        mWriteMsgs.push_back(msg);
        if (!writeInProgress)
        {
            doWrite();
        }
    };
    mIoService.post(lbdCompletHandler); //post是mIoService投递一个事件去执行,post能够同步执行，就不担心多个消息write
}

void ChatClient::close()
{
    auto lbdCompletHandler = [this]()
    {
        mSocket.close();
    };

    mIoService.post(lbdCompletHandler);
}

void ChatClient::doConnect(tcp::resolver::iterator endPointIterator)
{
    auto lbdConnectHandler = [this](boost::system::error_code ec, tcp::resolver::iterator)
    {
        if (!ec)
        {
            doReadHeader();
        }
    };
    boost::asio::async_connect(mSocket, endPointIterator, lbdConnectHandler);
}

void ChatClient::doReadHeader()
{
    auto lbdReadHandler = [this](boost::system::error_code ec, size_t)
    {
        if (!ec && mReadMsg.decodeHeader())
        {
            doReadBody();
        }
        else
        {
            mSocket.close();
        }
    };
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getData(), headerLength), lbdReadHandler);
}

void ChatClient::doReadBody()
{
    auto lbdReadHandler = [this](boost::system::error_code ec, size_t)
    {
        if (!ec)
        {
            if (mReadMsg.getType() == MT_ROOMINFO)
            {
                stringstream ss(string(mReadMsg.getBody(), mReadMsg.getBody()+mReadMsg.getBodyLength()));   //从消息把
                ptree tree;
                boost::property_tree::read_json(ss, tree);
                cout << "client ";
                cout << tree.get<string>("name");   //get是模板函数, tree.put<string>("name") 是给name键设置值
                cout << " says: ";
                cout << tree.get<string>("information");
                cout << endl;
            }
            doReadHeader();
        }
        else
        {
            mSocket.close();
        }
    };
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getBody(), mReadMsg.getBodyLength()), lbdReadHandler);
}

void ChatClient::doWrite()
{
    auto lbdWriteHandler = [this](boost::system::error_code ec, size_t)
    {
        if (!ec)
        {
            mWriteMsgs.pop_front();
            if (!mWriteMsgs.empty())
            {
                doWrite();
            }
        }
        else
        {
            mSocket.close();
        }
    };
    boost::asio::async_write(mSocket, boost::asio::buffer(mWriteMsgs.front().getData(), mWriteMsgs.front().getDataLength()), lbdWriteHandler);
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            cerr << "Usage: ChatClient <host> <port>" << endl;
        }
        io_service ioService;
        tcp::resolver resolver(ioService);
        auto endPointIterator = resolver.resolve(argv[1], argv[2]);
        ChatClient client(ioService, endPointIterator);
        auto lbdServiceRun = [&ioService]()
        {
            ioService.run();
        };
        thread t(lbdServiceRun);
        char line[maxBodyLength+1];
        while (cin.getline(line, maxBodyLength+1))
        {
            ChatMessage msg;
            auto type(0);
            string input(line, line+strlen(line));
            string output;
            if (parseJsonMessage(input, &type, output))
            {
                msg.setMessage(type, output.data(), output.size());
                client.write(msg);
                cout << "write message for server " << output.size() << endl;
            }
        }
        client.close(); //当socket.close后，被绑定的ioservice.run就停止工作
        t.join();
    } catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
