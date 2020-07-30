#include <iostream>

using namespace std;

class Test
{
public:
    explicit Test(int aNum = 1) //有参数的构造函数要加explicit, 防止隐式创建对象 Test t = 2;
    {
        mNum = aNum;
        cout << mNum << " construction" << endl;
    }
    ~Test()
    {
        cout << mNum << " destruction" << endl;
    }
private:
    int mNum;
};

int main()
{
    Test* test1 = new Test(0);
    Test* test2 = new Test[5];
    Test* test3 = (Test*)malloc(sizeof(Test));
    free(test3);
    delete[] test2;
    delete test1;
    return 0;
}
