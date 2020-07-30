#include <iostream>

using namespace std;

int main()
{
    int data[]{1, 2, 3, 4, 5, 6};

    auto iter(begin(data));
    advance(iter, 3);   //从1位置开始，向后增加3位就是4，如果是双向迭代器，第二个参数可以是负数
    cout << "Fourth element is " << *iter << endl;

    cout << "The number of elements in data is " << distance(begin(data), end(data)) << endl;   //返回begin和end两个迭代器之间的元素个数

    auto iter1(begin(data));
    auto v1(next(iter1, 3)); //iter1必须是一个正向迭代器，返回一个向后增加位置的迭代器
    cout << "4th is " << *v1 << endl;

    auto iter2(end(data));
    auto v2(prev(iter2, 4)); //iter2必须是一个反向或双向迭代器，返回一个向前增加位置的迭代器
    cout << "3th is " << *v2 << endl;
    return 0;
}
