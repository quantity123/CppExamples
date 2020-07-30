#include <iostream>

using namespace std;

class Book
{
public:
    Book(){};
    Book(string aTitle, double aPrice);
    void setPrice(double aPrice);
    double getPrice() const;
    void setTitle(string aTitle);
    string getTitle() const;
private:
    const string mS = "test const string";
    const int i = 2;
    double mPrice;
    string mTitle;
};

Book::Book(string aTitle, double aPrice)
{
    mTitle = aTitle;
    mPrice = aPrice;
}

void Book::setPrice(double aPrice)
{
    mPrice = aPrice;
    //mS = "ddd";   //常量初始化后就不能修改了
}

double Book::getPrice() const
{
    return mPrice;
    //setTitle("ddd"); //const 函数只能读取，这里报错
    //i = 300;  //常量初始化后就不能修改了
}

void Book::setTitle(string aTitle)
{
    mTitle = aTitle;
}

string Book::getTitle() const
{
    return mTitle;
}

Book& display(Book& b)
{
    cout << b.getTitle() << " " << b.getPrice() << endl;
    return b;
}

const Book& display2(const Book& b)
{
    cout << b.getTitle() << " " << b.getPrice() << endl;
    return b;
}

int main()
{
    Book* book = new Book;
    book->setPrice(5.23);
    book->setTitle("C++ program");
    cout << book->getTitle() << " " << book->getPrice() << endl;
    delete book;

    const Book* book1 = new Book("python program", 8.33);
    //boo1.setTitle("dddd"); // const常量对象不能访问非 const函数,这里报错
    cout << book1->getTitle() << " " << book1->getPrice() << endl;
    delete book1;

    Book book2("javascript program", 20.33);
    Book& book3 = display(book2);
    book3.setPrice(82.33);
    display(book3);
    display(book2);

    Book book4("C program", 44.66);
    Book book5 = display2(book4);
    book5.setPrice(55.77);
    display(book5);
    display(book4);
    return 0;
}
