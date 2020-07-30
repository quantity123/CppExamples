#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include "../chat_message.h"

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

using ChatMessageQueue = deque<ChatMessage>;

class ChatRoom;

class ChatSession : public enable_shared_from_this<ChatSession> //ChatSession是对应客户端
{
private:
    tcp::socket mSocket;
    ChatRoom& mRoom;
    ChatMessage mReadMsg;
    ChatMessageQueue mWriteMsgs;
    string mName;
    string mChatInformation;
    string buildRoomInfo() const;
    ptree toPtree();
    void handleMessage();
    void doReadHeader();
    void doReadBody();
    void doWrite();
public:
    ChatSession(tcp::socket socket, ChatRoom& room);
    void start();
    void deliver(const ChatMessage& msg);
};
using ChatSessionPtr = shared_ptr<ChatSession>;

class ChatRoom
{
private:
    set<ChatSessionPtr> mChatSessions;
    enum {maxRecentMsgs=100};
    ChatMessageQueue mRecentMsgs;
public:
    void join(const ChatSessionPtr& ChatSession);
    void leave(const ChatSessionPtr& ChatSession);
    void deliver(const ChatMessage& msg);
};

class ChatServer
{
private:
    tcp::acceptor mAcceptor;
    tcp::socket mSocket;
    ChatRoom mRoom;
    void doAccept();
public:
    ChatServer(boost::asio::io_service& ioService, const tcp::endpoint& endPoint);
};

string ChatSession::buildRoomInfo() const
{
    ptree tree;
    tree.put("name", mName);
    tree.put("information", mChatInformation);
    return ptreeToJsonString(tree);
}

ptree ChatSession::toPtree()
{
    ptree obj;
    stringstream ss(string(mReadMsg.getBody(), mReadMsg.getBody()+mReadMsg.getBodyLength()));
    boost::property_tree::read_json(ss, obj);
    return obj;
}

void ChatSession::handleMessage()
{
    int type = mReadMsg.getType();
    if (type == MT_BINDNAME)
    {
        auto nameTree = toPtree();
        mName = nameTree.get<string>("name");
    }
    else if (type == MT_CHATINFO)
    {
        auto chat = toPtree();
        mChatInformation = chat.get<string>("information");
        auto rinfo = buildRoomInfo();
        ChatMessage msg;
        msg.setMessage(MT_ROOMINFO, rinfo);
        mRoom.deliver(msg);
    }
}

void ChatSession::doReadHeader()
{
    auto self(shared_from_this());
    auto lbdReadHeaderHandler = [this, self](boost::system::error_code ec, size_t)
    {
        if (!ec && mReadMsg.decodeHeader())
        {
            doReadBody();
        }
        else
        {
            mRoom.leave(shared_from_this());
        }
    };
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getData(), headerLength), lbdReadHeaderHandler);
}

void ChatSession::doReadBody()
{
    auto self(shared_from_this());
    auto lbdReadBodyHandler = [this, self](boost::system::error_code ec, size_t)
    {
        if (!ec)
        {
            handleMessage();
            doReadHeader();
        }
        else
        {
            mRoom.leave(shared_from_this());
        }
    };
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getBody(), mReadMsg.getBodyLength()), lbdReadBodyHandler);
}

void ChatSession::doWrite()
{
    auto self(shared_from_this());
    auto lbdWriteDataHandler = [this, self](boost::system::error_code ec, size_t)
    {
        if (!ec)
        {
            mWriteMsgs.pop_front();
            if (!mWriteMsgs.empty())
            {
                doWrite();
            }
        }
    };
    boost::asio::async_write(mSocket, boost::asio::buffer(mWriteMsgs.front().getData(), mWriteMsgs.front().getDataLength()), lbdWriteDataHandler);
}

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room)
    : mSocket(move(socket)), mRoom(room)
{
}

void ChatSession::start()
{
    mRoom.join(shared_from_this());
    doReadHeader();
}

void ChatSession::deliver(const ChatMessage& msg)
{
    bool writeInProgress = !mWriteMsgs.empty();
    mWriteMsgs.push_back(msg);
    if (!writeInProgress)
    {
        doWrite();
    }
}

void ChatRoom::join(const ChatSessionPtr& ChatSession)
{
    mChatSessions.insert(ChatSession);
    for (const auto& msg: mRecentMsgs)
    {
        ChatSession->deliver(msg);
    }
}

void ChatRoom::leave(const ChatSessionPtr& ChatSession)
{
    mChatSessions.erase(ChatSession);
}

void ChatRoom::deliver(const ChatMessage& msg)
{
    mRecentMsgs.push_back(msg);
    while (mRecentMsgs.size() > maxRecentMsgs)
    {
        mRecentMsgs.pop_front();
    }
    for (const auto& ChatSession: mChatSessions)
    {
        ChatSession->deliver(msg);
    }
}

void ChatServer::doAccept()
{
    auto lbdAcceptHandler = [this](boost::system::error_code ec)
    {
        if (!ec)
        {
            auto session = make_shared<ChatSession>(move(mSocket), mRoom);  //智能指针是给类用的，无需手动析构类，模板实例也无需手动析构
            session->start();
        }
        doAccept();
    };
    mAcceptor.async_accept(mSocket, lbdAcceptHandler);
}

ChatServer::ChatServer(boost::asio::io_service& ioService, const tcp::endpoint& endPoint)
    : mAcceptor(ioService, endPoint), mSocket(ioService)
{
    doAccept();
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            cerr << "Usage: ChatServer <port> [<port>...]" << endl;
            return 1;
        }
        io_service ioService;
        list<ChatServer> servers;
        for (int i=1; i<argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), atoi(argv[i]));
            servers.emplace_back(ioService, endpoint);
        }
        ioService.run();    //服务持续运行不退出
    } catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
