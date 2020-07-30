#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define qttbool 123

void use_width()
{
    cout << qttbool << endl;


    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout.width(10);
        cout << v << '\n';
    }
}

void use_setw()
{
    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout << setw(10) << v << '\n';
    }
}

void use_fill()
{
    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout.width(10);
        cout.fill('*');
        cout << v << '\n';
    }
}

void use_setfill()
{
    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout.width(10);
        cout << setfill('*') << v << '\n';
    }
}

//科学型
void use_setprecision()
{
    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout << setprecision(1) << v << endl;
    }
}

//固定计数法
void use_setiosflags()
{
    double values[] = {1.23, 35.36, 653.7, 4345.27};
    for (auto v : values)
    {
        cout << setiosflags(ios::fixed) << setprecision(1) << v << endl;
    }
}

//不同进至的输出
void use_difrent_sys()
{
    cout << 3536 << endl;   //默认十进制
    cout << dec << 3536 << endl;    //十进制
    cout << oct << 3536 << endl;    //八进制
    cout << hex << 3536 << endl;    //十六进制
}

void readFromIfile()
{
    ifstream ifile;
    //ifstream ifile("./readfile.txt", ios::in);

    char buff[5] = {};

    ifile.open("./readfile.txt", ios::in);
    ifile.getline(buff, 5);   //从文件一行当中读取4个字母到buff
    ifile.close();
    cout << buff << endl;
}

void writeFromIFile()
{
    ofstream ofile;
    //ofstream ofile("./writefile.txt", ios::out);

    char buf[5] = {'b', 'b', 'b'};

    ofile.open("./writefile.txt", ios::out);
    if (!ofile)
    {
        cout << "打开文件失败!" << endl;
        return;
    }
    ofile << "aaa" << endl;
    ofile << buf << endl;
    ofile.write("ccc", 3);
    ofile.put('M');
    ofile.flush();  //清扫缓冲区
    ofile.close();
}

int main()
{
    use_width();
    use_setw();
    use_fill();
    use_setfill();
    use_setprecision();
    use_setiosflags();
    use_difrent_sys();
    readFromIfile();
    writeFromIFile();

    int sum = 0, val = 0;
    cout << "input a number:" << endl;
    while (cin >> val)
    {
        sum += val;
        cout << "input a number:" << endl;
    }
    cout << "the sum = " << sum << endl;

    return 0;
}
