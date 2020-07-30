#include <iostream>

using namespace std;

class book
{
public:
    static int mN;
    void setTitle(string title);
    string getTitle();
    static void test()
    {
        cout << "test" << endl;
        //cout << mTitle << endl; //静态成员函数只能访问静态成员变量，这里报错
        cout << mN << endl;
        static int ddd = 0;
        ddd += 1;
        cout << ddd << endl;
    }
private:
    string mTitle;
};
int book::mN = 10;

void book::setTitle(string title)
{
    this->mTitle = title;
    //cout << mN << endl; //普通成员函数可以访问静态成员变量
    static int eee = 0;
    eee += 1;
    cout << eee << endl;
}

string book::getTitle()
{
    return this->mTitle;
}

book b1;

book &initBook(string title)
{
    //static book b;
    b1.setTitle(title);
    b1.setTitle(title);
    return b1;
}

int main()
{
    //book &b = initBook("book C++");
    book b;
    b = initBook("book C++");
    cout << b.getTitle() << endl;
    b.test();   //类实例对象调用类函数
    book::test();   //类调用类函数，推荐类访问

    cout << b.mN << endl;   //类实例对象调用类变量
    cout << book::mN << endl;   //类调用类变量，推荐类访问

    book b2;
    b2.setTitle("ffffff");  //新的b2对象访问static静态变量和前面b对象形成累加效果
    b2.test();

    return 0;
}
