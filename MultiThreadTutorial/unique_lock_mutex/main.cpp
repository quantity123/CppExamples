#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

class MyMutex: public mutex
{
public:
    MyMutex(int id)
        : m_id(id)
    {
    }
    int getID()
    {
        return m_id;
    }
private:
    int m_id;
};

MyMutex mtx(101);

void print_ids(int id)
{
    unique_lock<MyMutex> lck(mtx);
    cout << "thread #" << id << " locked mutexID: " << lck.mutex()->getID() << endl;    //lck.mutex获取了MyMutex的指针
}

int main()
{
    vector<thread> threads;
    for (int i=0; i<10; ++i)
    {
        threads.emplace_back(print_ids, i+1);
    }
    for (auto& th: threads)
    {
        th.join();
    }
    return 0;
}
