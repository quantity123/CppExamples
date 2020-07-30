#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <memory>
#include <set>
#include <utility>
//#include <mutex>
#include <signal.h>
#include <boost/asio.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
//#include <boost/log/utility/setup/file.hpp>  //记录输出到文件
#include "../chat_message.h"
#include "../Protocal.pb.h"

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

using ChatMessageQueue = deque<ChatMessage>;

chrono::system_clock::time_point base;

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
    io_service::strand mStrand;
    string buildRoomInfo() const;
    bool fillProtobuf(::google::protobuf::Message* msg);
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
    //mutex mMutex;
    io_service::strand mStrand;
public:
    ChatRoom(io_service& ioService);
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
    PRoomInformation roomInfo;
    roomInfo.set_name(mName);
    roomInfo.set_information(mChatInformation);
    string out;
    auto ok = roomInfo.SerializeToString(&out);
    if (ok)
        return out;
    else
    {
        return "";
    }
}

bool ChatSession::fillProtobuf(::google::protobuf::Message* msg)
{
    string ss(mReadMsg.getBody(), mReadMsg.getBody()+mReadMsg.getBodyLength());
    auto ok = msg->ParseFromString(ss);
    return ok;
}

void ChatSession::handleMessage()
{
    int type = mReadMsg.getType();
    if (type == MT_BINDNAME)
    {
        PBindName bindName;
        if (fillProtobuf(&bindName))
        {
            mName = bindName.name();
        }
        else
        {
            return;
        }
    }
    else if (type == MT_CHATINFO)
    {
        PChat chat;
        if (fillProtobuf(&chat))
        {
            mChatInformation = chat.information();
        }
        else
        {
            return;
        }
        auto rinfo = buildRoomInfo();
        if (rinfo != "")
        {
            ChatMessage msg;
            msg.setMessage(MT_ROOMINFO, rinfo);
            mRoom.deliver(msg);
        }
        else
        {
            return;
        }
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
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getData(), headerLength), mStrand.wrap(lbdReadHeaderHandler));
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
    boost::asio::async_read(mSocket, boost::asio::buffer(mReadMsg.getBody(), mReadMsg.getBodyLength()), mStrand.wrap(lbdReadBodyHandler));
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
    boost::asio::async_write(mSocket, boost::asio::buffer(mWriteMsgs.front().getData(), mWriteMsgs.front().getDataLength()), mStrand.wrap(lbdWriteDataHandler));
}

ChatSession::ChatSession(tcp::socket socket, ChatRoom& room)
    : mSocket(move(socket)), mRoom(room), mStrand(socket.get_io_service())
{
}

void ChatSession::start()
{
    mRoom.join(shared_from_this());
    doReadHeader();
}

void ChatSession::deliver(const ChatMessage& msg)
{
    auto completionHandler = [this, msg]()
    {
        bool writeInProgress = !mWriteMsgs.empty();
        mWriteMsgs.push_back(msg);
        if (!writeInProgress)
        {
            doWrite();
        }
    };
    mStrand.post(completionHandler);
}

ChatRoom::ChatRoom(io_service& ioService)
    : mStrand(ioService)
{
}

void ChatRoom::join(const ChatSessionPtr& ChatSession)
{
    //lock_guard<mutex> lock(mMutex);   //strand替代mutex

    auto completionHandle = [this, ChatSession]()
    {
        mChatSessions.insert(ChatSession);
        for (const auto& msg: mRecentMsgs)
        {
            ChatSession->deliver(msg);
        }
    };
    mStrand.post(completionHandle);
}

void ChatRoom::leave(const ChatSessionPtr& ChatSession)
{
    //lock_guard<mutex> lock(mMutex);

    auto completionHandle = [this, ChatSession]()
    {
        mChatSessions.erase(ChatSession);
    };
    mStrand.post(completionHandle);
}

void ChatRoom::deliver(const ChatMessage& msg)
{
    //lock_guard<mutex> lock(mMutex);

    auto completionHandle = [this, msg]()
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
    };
    mStrand.post(completionHandle);
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
    : mAcceptor(ioService, endPoint), mSocket(ioService), mRoom(ioService)
{
    doAccept();
}

static function<void()> ioServiceSafeQuit;

void ioServiceSafeQuitHandler(int sig)
{
    BOOST_LOG_TRIVIAL(info) << "handle system signal " << sig;
    if (ioServiceSafeQuit)
    {
        ioServiceSafeQuit();
        ioServiceSafeQuit = nullptr;
    }
}

void initLogLevel()
{
    //boost::log::add_file_log("log.txt");
    auto corePtr = boost::log::core::get();
    corePtr->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
}

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    try
    {
        initLogLevel();
        BOOST_LOG_TRIVIAL(trace) << "trace log";
        BOOST_LOG_TRIVIAL(debug) << "debug log";
        BOOST_LOG_TRIVIAL(info) << "info log";
        BOOST_LOG_TRIVIAL(warning) << "warning log";
        BOOST_LOG_TRIVIAL(error) << "error log";
        BOOST_LOG_TRIVIAL(fatal) << "fatal log";
        if (argc < 2)
        {
            BOOST_LOG_TRIVIAL(info) << "Usage: ChatServer <port> [<port>...]" << endl;
            return 1;
        }
        io_service ioService;
        ioServiceSafeQuit = [&ioService]()
        {
            ioService.stop();
        };
        signal(SIGINT, ioServiceSafeQuitHandler);
        list<ChatServer> servers;
        for (int i=1; i<argc; ++i)  //监听端口的数量，几个参数，argc就是几
        {
            tcp::endpoint endpoint(tcp::v4(), atoi(argv[i]));
            servers.emplace_back(ioService, endpoint);
        }
        //ioService.run();    //服务持续运行不退出
        vector<thread> threadGroup; //创建多线程的vector容器，每个线程都跑io_service
        for (int i=0; i<5; ++i)
        {
            auto lbdRunIoService = [&ioService]()
            {
                ioService.run();
            };
            threadGroup.emplace_back(lbdRunIoService);
        }
        for (auto& t : threadGroup)
        {
            t.join();   //等待每个线程退出
        }
    } catch (exception& e)
    {
        BOOST_LOG_TRIVIAL(info) << "Exception: " << e.what() << endl;
        return 1;
    }
    google::protobuf::ShutdownProtobufLibrary();
    BOOST_LOG_TRIVIAL(info) << "safe release all resource and quit";
    return 0;
}
