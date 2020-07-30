#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void stackFunc()
{
    stack<int> s;   //stack容器适配器由deque容器衍生而来

    s.push(0);
    s.push(1);
    s.push(2);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void queueFunc()
{
    queue<int> q;   //queue容器适配器由deque容器衍生而来

    q.push(2);
    q.push(0);
    q.push(1);
    cout << q.back() << endl;   //尾部项
    cout << q.front() << endl;  //头部项
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void priority_queueFunc()
{
    priority_queue<int> pq; //priority_queue容器适配器属于queue，所以也是由deque容器衍生而来

    pq.push(2);
    pq.push(0);
    pq.push(1);

    cout << pq.top() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << endl;   //优先级是按照从大到小的顺序删除元素
        pq.pop();
    }
}

int main()
{
    //stackFunc();
    //queueFunc();
    priority_queueFunc();
    return 0;
}
