#include <iostream>

using namespace std;

int main()
{
    string s1 = "abcdefg";
    for (unsigned i=0; i<s1.length(); i++)
    {
        cout << s1[i] << ", ";
    }
    cout << endl;
    s1[4] = '4';
    cout << s1 << endl;

    string s2, s3;
    s1 = s2 = s3 = "0123456789";
    s2.erase(4, 3); //第1个参数为擦除的起始位置，第二个参数擦除长度
    s3.erase(4);    //参数为擦除的起始位置
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    s1 = s2 = "0123456789";
    s3 = "aaa";
    s1.insert(4, s3);   //第一个参数插入的起始位置，第二个参数为插入的字符串
    s2.insert(4, "bbb");
    cout << s1 << endl;
    cout << s2 << endl;

    s1 = s2 = "0123456789";
    s3 = "aaa";
    s1.replace(4, 4, s3);   //第一个参数为被替换的起始位置，第二个参数为被替换的长度，第三个参数为替换的字符串
    cout << s1 << endl;
    s2.replace(4, 2, "bbb");
    cout << s2 << endl;


    s1 = "aaaaaa";
    s2 = "bbbb";
    s1.swap(s2);    //字符串相互交换
    cout << s1 << endl;
    cout << s2 << endl;

    s1 = "first second third";
    s2 = s1.substr(6, 9);   //第一个参数为提取的字符串起始位置，第二个参数为提取的长度。
    cout << s1 << endl;
    cout << s2 << endl;

    s1 = "first second third";
    s2 = "second";
    //unsigned index = s1.find(s2); //第二个参数不设置的话则从最开始0位置查找。
    unsigned index = s1.find(s2, 5);    //第二个参数从第5个位置开始查找
    cout << "find index:" << index << endl;
    index = s1.rfind(s2, 5);    //第二个参数是最多查找到位置处结束查找。
    cout << "rfind index:" << index << endl;

    s1 = "first second second third";
    s2 = "aaaaasecond";
    index = s1.find_first_of(s2);   //s1和s2共同拥有的第一个字符，并且在s1中首字符索引的位置，这里找到 s1 first 中 s 字符
    cout << "find_first_of index:" << index << endl;

    s1 = "secondsecondthird";
    s2 = "asecond";
    index = s1.find_first_not_of(s2);   //s1和s2不共同拥有的第一个字符，并且在s1中首字符索引的位置。这里找到 s1 third 中 t 字符
    cout << "find_first_not_of index:" << index << endl;

    s1 = "secondsecondthird";
    s2 = "secondthird";
    if (s1 == s2)
        cout << "==" << endl;
    if (s1 != s2)
        cout << "!=" << endl;
    if (s1 < s2)
        cout << "<" << endl;
    if (s1 <= s2)
        cout << "<=" << endl;
    if (s1 > s2)
        cout << ">" << endl;
    if (s1 >= s2)
        cout << ">=" << endl;
    return 0;
}
