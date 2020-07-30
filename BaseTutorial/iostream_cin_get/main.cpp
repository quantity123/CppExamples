#include <iostream>

using namespace std;

int main()
{
    char c;
    while ((c = cin.get()) != EOF)  //get函数遇到空格，tab，换行不会像cin那样忽略，当作一个字符
    {
        cout.put(c);
    }
    cout << endl;
    return 0;
}
