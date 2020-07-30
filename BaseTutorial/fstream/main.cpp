#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //写入字符串数据
    ofstream ofs;
    ofs.open("a.txt");
    ofs << "127.0.0.1" << endl;
    ofs << "3000";
    ofs.close();
    //读出字符串数据
    string s;
    ifstream ifs;
    ifs.open("a.txt");
    while (getline(ifs, s))
    {
        cout << s << endl;
    }
    ifs.close();
    return 0;
}
