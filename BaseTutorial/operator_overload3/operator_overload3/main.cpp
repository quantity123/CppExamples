#include <iostream>

using namespace std;

class Complex
{
public:
    Complex();
    Complex(double a);
    Complex(double a, double b);
    friend Complex operator+(const Complex& aComplex1, const Complex& aComplex2);   //把下面的顶层函数声明成为类的友元函数就可以直接访问私有成员
    friend Complex operator-(const Complex& aComplex1, const Complex& aComplex2);
    friend Complex operator*(const Complex& aComplex1, const Complex& aComplex2);
    friend Complex operator/(const Complex& aComplex1, const Complex& aComplex2);
    void display() const;
private:
    double mReal;   //复数的实部
    double mImag;   //复数的虚部
};

Complex::Complex()
{
    mReal = 0;
    mImag = 0;
}

Complex::Complex(double a)
{
    mReal = a;
    mImag = 0;
}

Complex::Complex(double a, double b)
{
    mReal = a;
    mImag = b;
}

void Complex::display() const
{
    cout << mReal << " + " << mImag << "i";
}

Complex operator+(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    comp.mReal = aComplex1.mReal + aComplex2.mReal;
    comp.mImag = aComplex1.mImag + aComplex2.mImag;
    return comp;
}

Complex operator-(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    comp.mReal = aComplex1.mReal - aComplex2.mReal;
    comp.mImag = aComplex1.mImag - aComplex2.mImag;
    return comp;
}

Complex operator*(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    comp.mReal = aComplex1.mReal * aComplex2.mReal - aComplex1.mImag * aComplex2.mImag;
    comp.mImag = aComplex1.mImag * aComplex2.mReal + aComplex1.mReal * aComplex2.mImag;
    return comp;
}

Complex operator/(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    double square = aComplex2.mReal * aComplex2.mReal + aComplex2.mImag * aComplex2.mImag;
    comp.mReal = (aComplex1.mReal * aComplex2.mReal + aComplex1.mImag * aComplex2.mImag) / square;
    comp.mImag = (aComplex1.mImag * aComplex2.mReal - aComplex1.mReal * aComplex2.mImag) / square;
    return comp;
}

int main()
{
    Complex c1(4.3, -5.8);
    Complex c2(8.4, 6.7);
    Complex c3;

    //复数的加法
    c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();
    cout << endl;

    //复数的减法
    c3 = c1 - c2;
    cout << "c1 - c2 = ";
    c3.display();
    cout << endl;

    //复数的乘法
    c3 = c1 * c2;
    cout << "c1 * c2 = ";
    c3.display();
    cout << endl;

    //复数的除法
    c3 = c1 / c2;
    cout << "c1 / c2 = ";
    c3.display();
    cout << endl;

    Complex a1, a2(15.5, 23.1);
    a1 = a2 + 13.5;
    a1 = 13.5 + a2;

    return 0;
}
