#include <iostream>
#include <set>
#include <map>

using namespace std;

void setFunc()
{
    set<int> s; //不重复元素的集合
    //multiset<int> s;   //可重复元素的集合

    s.insert(5);	//set插入数据默认是排好序的
    s.insert(1);
    s.insert(0);
    s.insert(1);    //前面有一个数据1,所以再次插入1数据,集合里会不存在
    s.insert(s.begin(), 2);
    s.insert(s.end(), 4);
    set<int>::iterator iter;
    for (iter=s.begin(); iter!=s.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    iter = s.find(2);
    if (iter == s.end())
        cout << "not find 2!" << endl;
    else
        cout << "found 2!" << endl;

    bool index = s.count(2);
    if (index)
        cout << "found 2!" << endl;
    else
        cout << "not find 2!" << endl;

    //3是不存在集合里的，那么下面函数就会找到并返回目前插入的数字的位置
    auto lb = s.lower_bound(3);
    cout << "lower bound for 3 = " << *lb << endl;

    auto ub = s.upper_bound(3);
    cout << "upper_bound for 3 = " << *ub << endl;

    auto er = s.equal_range(3);
    cout << "upper_bound for 3 = " << *er.first << " : " << *er.second << endl;

    //4是存在集合里的，那么下面函数就会找到并返回目前4数字的位置上下边界数字或者范围
    lb = s.lower_bound(4);
    cout << "lower bound for 4 = " << *lb << endl;

    ub = s.upper_bound(4);
    cout << "upper_bound for 4 = " << *ub << endl;

    er = s.equal_range(4);
    cout << "upper_bound for 4 = " << *er.first << " : " << *er.second << endl;
}

void mapFunc()
{
    map<string, int> m;
    //multimap<string, int> m;	////可重复键的映射容器

    m["aa"] = 0;
    m["bb"] = 1;
    m["cc"] = 2;
    m["aa"] = 0;    //不重复键的映射容器
    map<string, int>::const_iterator iter;
    for (iter=m.begin(); iter!=m.end(); iter++)
    {
        cout << iter->first << " = " << iter->second << endl;
    }
    cout << m.at("cc") << endl;
}

int main()
{
    setFunc();
    mapFunc();
    return 0;
}
