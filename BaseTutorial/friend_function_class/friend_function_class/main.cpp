#include <iostream>

using namespace std;

class Book
{
public:
    Book(){}
    Book(string aTitle, double aPrice);
    friend void display(Book& b);   //用friend关键字把display外部函数声明成这里友元函数就可以通过传类的参数访问类私有成员
    //void display(Book &b);    //如果不加friend关键字成友元函数，则访问不了私有成员变量。
private:
    double mPrice;
    string mTitle;
};

Book::Book(string aTitle, double aPrice)
{
    mTitle = aTitle;
    mPrice = aPrice;
}

void display(Book& b)
{
    cout << "book_title: " << b.mTitle << ", " << "book_price: " << b.mPrice << endl;
}

class Time;

class Date
{
public:
    Date(int aY, int aM, int aD);
    void display(Time& aT);
private:
    int mYear, mMonth, mDay;
};

class Time
{
public:
    Time(int aH, int aM, int aS);
    //friend void Date::display(Time& aT);    //用friend关键字把Date::display类函数声明到Time类这里成类友元函数后 display函数就可以传Time类的参数访问Time类的私有成员
private:
    int mHour, mMinute, mSecond;
    friend Date;    // 用friend关键字把Date类声明到这里成Time类的友元类，那么Date类所有的函数都可以访问Time类的私有成员
};

Date::Date(int aY, int aM, int aD)
{
    mYear = aY;
    mMonth = aM;
    mDay = aD;
}

void Date::display(Time& aT)
{
    cout << "The datetime is: ";
    cout << mYear << "/" << mMonth << "/" << mDay << " ";
    cout << aT.mHour << ":" << aT.mMinute << ":" << aT.mSecond << endl;
}

Time::Time(int aH, int aM, int aS)
{
    mHour = aH;
    mMinute = aM;
    mSecond = aS;
}

int main()
{
    //外部函数友元函数
    Book book1("C++ Program", 30.33);
    display(book1);

    //类函数友元函数
    Date date(2020, 2, 18);
    Time time(18, 10, 30);
    date.display(time);


    return 0;
}
