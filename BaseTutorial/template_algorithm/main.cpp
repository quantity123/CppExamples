#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b)
{
    return a > b;
}

void display(int i)
{
    cout << i << " ";
}

bool odd(int i)
{
    return i % 2 != 0;
}

int main()
{
    //vector<int> num(10);
    vector<int> num;

    //生成随机数字，填充num
    //generate(num.begin(), num.end(), rand);
    num.push_back(1);
    num.push_back(4);
    num.push_back(3);
    num.push_back(2);
    for_each(num.begin(), num.end(), display);
    cout << endl;

    //将其中的奇数全部替换成0
    replace_if(num.begin(), num.end(), odd, 0);
    for_each(num.begin(), num.end(), display);
    cout << endl;

    //从大到小排序
    sort(num.begin(), num.end(), compare);
    for_each(num.begin(), num.end(), display);
    cout << endl;
    return 0;
}
