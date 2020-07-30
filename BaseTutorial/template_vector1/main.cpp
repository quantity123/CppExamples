#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;    //vector普通的数组，在非尾部插入元素都需要移动其它元素。
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
    for (auto v : num)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
