#include <queue>
#include <memory>
#include <boost/asio.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include "../DataPacket/data_packet.h"
#include "../DataPacket/DataPackageStruct/Protocal.pb.h"

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::io_service;

using CSendDataPacketQueue = queue<CDataPacket>;

class CClient
{
private:
    tcp::socket mSocket;
    CDataPacket mReceiveDataPacket;
    CSendDataPacketQueue mSendDataPacketQueue;
    void sendDataPacketToServer()
    {
        auto lbdSendDataPacketToServer = [this](boost::system::error_code ec, size_t)
        {
            if (!ec)
            {
                mSendDataPacketQueue.pop();
                if (!mSendDataPacketQueue.empty())
                    sendDataPacketToServer();
            }
        };
        boost::asio::async_write(mSocket, boost::asio::buffer(mSendDataPacketQueue.front().getDataPacket(), mSendDataPacketQueue.front().getDataPacketLength()), lbdSendDataPacketToServer);
    }
    void pushDataPacketIntoSendQueue(const CDataPacket& aDataPacket)
    {
        bool isEmpty = mSendDataPacketQueue.empty();
        mSendDataPacketQueue.push(aDataPacket);
        if (isEmpty)
        {
            sendDataPacketToServer();
        }
    }
    void processReceiveDataBody()
    {
        DataBodyType dataBodyType = mReceiveDataPacket.getDataBodyType();
        switch (dataBodyType)
        {
            case DBT_CLIENT_LOGIN_FEED_BACK:
            {
                bool loginFeedback = mReceiveDataPacket.getClientLoginFeedback();
                if (loginFeedback)
                    BOOST_LOG_TRIVIAL(info) << "Login Success!!";
                else
                    BOOST_LOG_TRIVIAL(info) << "Login failure!!";
                break;
            }
            case DBT_TEST_CLIENT_ONLINE:
            {
                bool isOnline = mReceiveDataPacket.getClientIsOnline();
                BOOST_LOG_TRIVIAL(info) << "Get Server Test Client Online DataPacket: " << isOnline;
                if (!isOnline)
                {
                    CDataPacket dataPacket;
                    dataPacket.buildTestClientOnline(true);
                    pushDataPacketIntoSendQueue(dataPacket);
                }
                break;
            }
            default:
            {
                BOOST_LOG_TRIVIAL(error) << dataBodyType << " number is not DataBodyType!";
                break;
            }
        }
    }
    void receiveDataBody()
    {
        auto receiveDataBodyCallBack = [this](boost::system::error_code ec, size_t)
        {
            if (!ec)
            {
                processReceiveDataBody();
                receiveDataPacketHead();
            }
        };
        boost::asio::async_read(mSocket, boost::asio::buffer(mReceiveDataPacket.getDataBody(), mReceiveDataPacket.getDataBodyLength()), receiveDataBodyCallBack);
    }
    void receiveDataPacketHead()
    {
        auto receiveDataPacketHeadCallBack = [this](boost::system::error_code ec, size_t)
        {
            if (!ec && mReceiveDataPacket.decodeDataHead())
            {
                receiveDataBody();
            }
        };
        boost::asio::async_read(mSocket, boost::asio::buffer(mReceiveDataPacket.getDataPacket(), DATA_HEAD_LENGTH), receiveDataPacketHeadCallBack);
    }
    void doConnect(tcp::resolver::iterator endPointIterator)
    {
        auto connectCallback = [this](boost::system::error_code ec, tcp::resolver::iterator)
        {
            if (!ec)
                receiveDataPacketHead();
        };
        boost::asio::async_connect(mSocket, endPointIterator, connectCallback);
    }
public:
    CClient(io_service& aIoService, tcp::resolver::iterator aEndPointIterator)
        : mSocket(aIoService)
    {
        doConnect(aEndPointIterator);
    }
    bool login(string& aInput)
    {
        CDataPacket dataPacket;
        if (dataPacket.buildClientLogin(aInput))
        {
            pushDataPacketIntoSendQueue(dataPacket);
            return true;
        }
        return false;
    }
    void close()
    {
        mSocket.close();
    }
};

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    try
    {
        if (argc != 3)
        {
            cerr << "Usage: ChatClient <host> <port>" << endl;
        }
        io_service ioService;
        tcp::resolver resolver(ioService);
        auto endPointIterator = resolver.resolve(argv[1], argv[2]);
        CClient client(ioService, endPointIterator);
        auto lbdServiceRun = [&ioService]()
        {
            ioService.run();    //另一个线程run保持服务持续工作，让主线程可以做输入操作
        };
        thread t(lbdServiceRun);
        char line[MAX_DATA_BODY_LENGTH+1];
        while (cin.getline(line, MAX_DATA_BODY_LENGTH+1))
        {
            string input(line, line+strlen(line));
            if (client.login(input))
                break;
        }
        t.join();
        client.close();
    }
    catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
