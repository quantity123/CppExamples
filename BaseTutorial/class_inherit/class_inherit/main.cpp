#include <iostream>

using namespace std;

enum CodeLanguage{cpp, java, python, javascript};

class Book
{
public:
    void setTitle(const string aTitle);
    string getTitle() const;
    void setPrice(const double aPrice);
    double getPrice() const;
    void dispaly();
private:
    string mTitle;
    double mPrice;
};

void Book::setTitle(const string aTitle)
{
    mTitle = aTitle;
}

string Book::getTitle() const
{
    return mTitle;
}

void Book::setPrice(const double aPrice)
{
    mPrice = aPrice;
}

double Book::getPrice() const
{
    return mPrice;
}

void Book::dispaly()
{
    cout << "book title: " << mTitle << ", " << "book price: " << mPrice << endl;
}

class CodingBook: protected Book
{
public:
    void setCodeLang(CodeLanguage aCodeLang);
    CodeLanguage getCodeLang() const;
    using Book::setTitle;   // using声明能改变父类的成员(变量或函数)属性为private或protected或public
protected:
    void testCodeLang()
    {
        cout << "testCodeLang" << endl;
    }
private:
    CodeLanguage mCodeLang;
};

void CodingBook::setCodeLang(CodeLanguage aCodeLang)
{
    mCodeLang = aCodeLang;
    setTitle("ddd");
    setPrice(3.44);
}

CodeLanguage CodingBook::getCodeLang() const
{
    return mCodeLang;
}

int main()
{
    CodingBook cb;
    cb.setTitle("ddd");
    return 0;
}
