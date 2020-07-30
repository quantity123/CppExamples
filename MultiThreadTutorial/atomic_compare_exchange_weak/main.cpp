#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

atomic<Node*> list_head(nullptr);

//生产者
void append(int val)
{
    Node* newNode = new Node{val, list_head};   //结构体可以用{}大括号初始化
    //list_head原子与newNode->next比较，相等则用newNode替换list_head，不相等则用list_head替换newNode
    //while (!list_head.compare_exchange_strong(newNode->next, newNode))    //strong操作不允许返回false,无论底层物理内容是否不同，即list_head原子与newNode->next相等一定返回true
    while (!list_head.compare_exchange_weak(newNode->next, newNode))
    {
    }
}

int main()
{
    vector<thread> threads;
    for (int i=0; i<10; ++i)
    {
        threads.push_back(thread(append, i));
    }
    for (auto& th: threads)
    {
        th.join();
    }
    //消费者
    for (Node* it=list_head; it!=nullptr; it=it->next)
    {
        cout << " " << it->value;
    }
    cout << endl;
    //delete 前面new出来的结构体
    Node* it;
    while (it=list_head)
    {
        list_head = it->next;
        delete it;
    }
    return 0;
}
