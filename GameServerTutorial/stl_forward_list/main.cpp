#include <iostream>
#include <forward_list>

using namespace std;

using forwardList = forward_list<float>;

int main()
{
    forwardList fl{1.2f, 3.3f, 4.5f, 6.6f}; //数据后面加f表示float类型,不加默认double类型
    for (auto v : fl)
        cout << v << " ";
    cout << endl;

    //insert_after表示插入某索引位置后面
    fl.insert_after(fl.begin(), 2.2f);   //begin是第[0]索引位置,也就是首位
    fl.insert_after(fl.before_begin(), 0.5f);    //before_begin()是第[0]索引位置前面一位
    //fl.insert_after(fl.end(), 0.8f); //end是最后一个索引位置,所以后面没有了，插入后面报错

    //删除某索引位置后面
    fl.erase_after(fl.before_begin());

    fl.push_front(6.99f);   //最前面索引位置压入数据
    //fl.pop_front(); //最前面索引位置弹出数据

    fl.emplace_front(8.8f); //把数据放置在最前面
    fl.emplace_after(fl.begin(), 10.11f);    //把数据放置在某索引位置后面
    fl.emplace_after(fl.begin(), 10.11f);

    //fl.reverse();   //反转整个列表数据的顺序

    //fl.resize(5);   //重新设置空间大小

    //fl.remove(6.6f); //指定删除某个数据

    //fl.sort();  //正排序

    //fl.clear(); //清空列表

    //fl.unique();    //去掉重复的数据


    forwardList fl2{12.11, 13.22};

    fl.merge(fl2);  //合并两个列表数据

    for (auto v : fl)
        cout << v << " ";
    cout << endl;
    return 0;
}
