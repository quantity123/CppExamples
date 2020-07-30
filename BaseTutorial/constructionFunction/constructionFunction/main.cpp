#include <iostream>

using namespace std;

class book
{
public:
    explicit book(string aTitle = "Book1"); //有参数的构造函数要加explicit,防止隐式创建对象 book b = "C++";
    string getTitle();
private:
    string mTitle;
};

book::book(string aTitle)
{
    mTitle = aTitle;
}

string book::getTitle()
{
    return mTitle;
}

int main()
{
    //book b;
    book b("Book2");
    cout << b.getTitle() << endl;
    return 0;
}
