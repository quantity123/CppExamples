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

class ChatParticipant
{
public:
    virtual ~ChatParticipant();
    virtual void deliver(const ChatMessage& msg) = 0;
};
using ChatParticipantPtr = shared_ptr<ChatParticipant>;

ChatParticipant::~ChatParticipant()
{
}

class ChatRoom
{
private:
    set<ChatParticipantPtr> mParticipants;
    enum {maxRecentMsgs=100};
    ChatMessageQueue mRecentMsgs;
public:
    void join(const ChatParticipantPtr& participant);
    void leave(const ChatParticipantPtr& participant);
    void deliver(const ChatMessage& msg);
};

void ChatRoom::join(const ChatParticipantPtr& participant)
{
    mParticipants.insert(participant);
    for (const auto& msg: mRecentMsgs)
    {
        participant->deliver(msg);
    }
}

void ChatRoom::leave(const ChatParticipantPtr& participant)
{
    mParticipants.erase(participant);
}

void ChatRoom::deliver(const ChatMessage& msg)
{
    mRecentMsgs.push_back(msg);
    while (mRecentMsgs.size() > maxRecentMsgs)
    {
        mRecentMsgs.pop_front();
    }
    for (const auto& participant: mParticipants)
    {
        participant->deliver(msg);
    }
}

class ChatSession : public ChatParticipant, public enable_shared_from_this<ChatSession> //ChatSession是对应客户端
{
private:
    tcp::socket mSocket;
    ChatRoom& mRoom;
    ChatMessage mReadMsg;
    ChatMessageQueue mWriteMsgs;
    string mName;
    string mChatInformation;
    RoomInformation buildRoomInfo() const;
    void handleMessage();
    void doReadHeader();
    void doReadBody();
    void doWrite();
public:
    ChatSession(tcp::socket socket, ChatRoom& room);
    void start();
    void deliver(const ChatMessage& msg);
};

RoomInformation ChatSession::buildRoomInfo() const
{
    RoomInformation info;
    info.name.nameLen = mName.size();
    memcpy(info.name.name, mName.data(), mName.size());
    info.chat.infoLen = mChatInformation.size();
    memcpy(info.chat.information, mChatInformation.data(), mChatInformation.size());
    return info;
}

void ChatSession::handleMessage()
{
    int type = mReadMsg.getType();
    if (type == MT_BINDNAME)
    {
        const BindName* bind = reinterpret_cast<const BindName*>(mReadMsg.getBody());
        mName.assign(bind->name, bind->name+bind->nameLen); //assign函数第一个参数name字符，第二个参数从name地址到namelen地址之间的长度
    }
    else if (type == MT_CHATINFO)
    {
        const ChatInformation* chatInformation = reinterpret_cast<const ChatInformation*>(mReadMsg.getBody());
        mChatInformation.assign(chatInformation->information, chatInformation->information+chatInformation->infoLen);
        auto rinfo = buildRoomInfo();
        ChatMessage msg;
        msg.setMessage(MT_ROOMINFO, &rinfo, sizeof(rinfo));
        mRoom.deliver(msg);
    }
    else
    {

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
