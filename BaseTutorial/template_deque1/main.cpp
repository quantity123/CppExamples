#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> num; //deque主要在头部或尾部增加或删除数据，效率优于vector

    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    for (auto v : num)
    {
        cout << v << " ";
    }
    cout << endl;
    num.insert(num.begin(), 4); //begin是指定插入第一个位置
    num.insert(num.end(), 0);   //end是指定插入最后一个位置
    for (auto v : num)
    {
        cout << v << " ";
    }
    cout << endl;
    cout << "num size:" << num.size() << endl;
    num.erase(num.begin());
    num.push_front(6);
    for (auto v : num)
    {
        cout << v << " ";
    }
    cout << endl;
    num.pop_front();
    num.pop_back();
    for (auto v : num)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
