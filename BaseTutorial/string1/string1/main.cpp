#include <iostream>

using namespace std;

int main()
{
    string s(10, 'a');
    cout << s << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.length() << endl;

    string s0 = "bbbbb";
    string s1 = "cccccc";
    string ss = s0 + s1;
    cout << ss << endl;
    ss += "dddd";
    cout << ss << endl;

    auto len1 = s.size();
    auto len2 = s1.length();
    cout << len1 << endl;
    cout << len2 << endl;

    string s2 = "", s3 = "";
    cin >> s2 >> s3;
    cout << s2 << s3 << endl;

    string str = "some string";
    for (char c: str)
        cout << c << endl;

    //str.c_str()   // 把字符串类型转换为 c 的字符串指针类型

    return 0;
}
