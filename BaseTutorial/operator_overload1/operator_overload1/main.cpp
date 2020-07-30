#include <iostream>

using namespace std;

class Complex
{
public:
    Complex();
    Complex(double a);
    Complex(double a, double b);
    Complex operator+(const Complex& aComplex) const;
    Complex operator-(const Complex& aComplex) const;
    Complex operator*(const Complex& aComplex) const;
    Complex operator/(const Complex& aComplex) const;
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

Complex Complex::operator+(const Complex& aComplex) const
{
    Complex comp;
    comp.mReal = mReal + aComplex.mReal;
    comp.mImag = mImag + aComplex.mImag;
    return comp;
}

Complex Complex::operator-(const Complex& aComplex) const
{
    Complex comp;
    comp.mReal = mReal - aComplex.mReal;
    comp.mImag = mImag - aComplex.mImag;
    return comp;
}

Complex Complex::operator*(const Complex& aComplex) const
{
    Complex comp;
    comp.mReal = mReal * aComplex.mReal - mImag * aComplex.mImag;
    comp.mImag = mImag * aComplex.mReal + mReal * aComplex.mImag;
    return comp;
}

Complex Complex::operator/(const Complex& aComplex) const
{
    Complex comp;
    double square = aComplex.mReal * aComplex.mReal + aComplex.mImag * aComplex.mImag;
    comp.mReal = (mReal * aComplex.mReal + mImag * aComplex.mImag) / square;
    comp.mImag = (mImag * aComplex.mReal - mReal * aComplex.mImag) / square;
    return comp;
}

void Complex::display() const
{
    cout << mReal << " + " << mImag << "i";
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
    cout << "a2 + 13.8 = ";
    a1.display();
    cout << endl;

    return 0;
}
