#include <iostream>

using namespace std;

int main()
{
    //格式标识来控制----------------------------------------------------------------------------------------------------------
                                    //设置新格式标识，返回旧标识
    ios_base::fmtflags old_val = cout.flags(ios_base::left | ios_base::hex | ios_base::uppercase | ios_base::showbase);

    for(int i=100; i<150; i++)
    {
        cout << i << endl;
    }
    cout << endl << endl;   //endl还可以用来隔行
    //清除指定的标识，返回旧标识，在后面设置新的标识格式前先将原有设置的格式标识都取消
    cout.unsetf(ios_base::left | ios_base::hex | ios_base::uppercase);

    cout.setf(old_val); //设置旧的默认的标识
    for(int i=100; i<150; i++)
    {
        cout << i << endl;
    }
    cout << endl << endl;
    cout.unsetf(old_val);

    cout.setf(ios_base::hex | ios_base::uppercase);
    cout << "hex=" << 170 << endl;
    cout.unsetf(ios_base::hex | ios_base::uppercase);

    cout.setf(ios_base::oct);
    cout << "oct=" << 170 << endl;
    cout.unsetf(ios_base::oct);

    cout.setf(ios_base::dec);
    cout << "dec=" << 170 << endl;
    cout.unsetf(ios_base::dec);

    cout.width(6);  //设置输出宽度为6个字符位置
    cout << -10 << endl;    //默认输出采用ios_base::right右对齐方式

    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.width(6);
    cout << -10 << endl;
    cout.unsetf(ios_base::left);

    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.width(12);
    cout << -10 << endl;
    cout.unsetf(ios_base::right);




    //操纵器来控制-----------------------------------------------------------------------------------------------------------------------------------------------
    cout << hex << uppercase << "hex=" << 170 << endl;  //uppercase指定输出字母为大写
    cout << oct << "oct=" << 170 << endl;
    cout << dec << "dec=" << 170 << endl;

    return 0;
}
