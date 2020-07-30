#include <iostream>
#include <map>

using namespace std;

int main()
{
    using mapGroup = map<int, string>;
    mapGroup mg{{1, "aa"}, {2, "bb"}, {3, "cc"}};
    auto num = mg.count(2);
    if (num)
        cout << "2 in mg" << endl;
    else
        cout << "2 not in mg" << endl;
    auto findIter = mg.find(3);
    if (findIter == mg.end())
        cout << "3 not in mg" << endl;
    else
        cout << "3 in mg" << endl;
    auto lower = mg.lower_bound(1);
    if (lower != mg.end())
        cout << "lower_bound(1): " << lower->first << "=" << lower->second << endl;
    auto upper = mg.upper_bound(1);
    if (upper != mg.end())
        cout << "upper_bound(1): " << upper->first << "=" << upper->second << endl;
    auto range = mg.equal_range(1);
    if (range.first != range.second)    //这个first和second边界只能用作判断不能打印值
        cout << "equal_range(1): 1 in mg" << endl;

    mapGroup mg2;
    mg2.insert(mg.begin(), mg.end());
    mg2.insert(make_pair(4, "dd"));
    //mg2.insert(5, "ee"); //错误
    mg2.emplace(make_pair(5, "ee"));
    mg2.emplace(6, "ff");
    mg2.emplace_hint(mg2.begin(), 7, "gg"); //自动根据(1-7)进行排序，所以7排最后
    for (auto& v: mg2)
    {
        cout << v.first << ":" << v.second << ", ";
    }
    cout << endl;

    return 0;
}
