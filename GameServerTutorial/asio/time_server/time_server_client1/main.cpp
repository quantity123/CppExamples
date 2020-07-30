#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::io_service;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            cerr << "Usage: client <host>" << endl;
            return 1;
        }
        io_service io_serv;
        tcp::resolver rsv(io_serv); //创建分解器并绑定io_service
        tcp::resolver::query qry(argv[1], "3000");   //创建查询器并根据参数和服务去查询
        tcp::resolver::iterator conn_info_iter = rsv.resolve(qry);    //分解器根据查询器查询获得IP和端口等连接信息并赋值给 分解器迭代器
        tcp::socket sock(io_serv);  //创建套接字并绑定io_service
        boost::asio::connect(sock, conn_info_iter);
        //connect(sock, conn_info_iter);    //和上面一样可以用
        while (true)
        {
            boost::array<char, 128> buf;    //创建一个buf,循环结束会自动析构这个buf
            //array<char, 128> buf; //和上面一样可以用
            boost::system::error_code err;
            size_t read_some_len = sock.read_some(boost::asio::buffer(buf), err);
            if (err == boost::asio::error::eof) //如果从网络读取数据结尾则退出循环
            {
                break;
            }
            else if (err)   //如果错误为真就抛出异常
            {
                throw boost::system::system_error(err);
            }
            cout.write(buf.data(), read_some_len);
        }
    } catch (exception& err)
    {
        cerr << err.what() << endl;
    }
    return 0;
}
