#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    cout << "The array contains:" << endl;
    double data[]{2.5, 4.5, 6.5, 5.5, 8.5};
    for (auto iter=begin(data); iter!=end(data); ++iter)
    {
        cout << *iter << endl;
    }
    auto total = accumulate(begin(data), end(data), 0.0);   //算法计算data数组元素的总和，从迭代器begin到end
    cout << "The sum of the array elements is " << total << endl;
    return 0;
}
