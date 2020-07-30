#include <iostream>

using namespace std;

class Complex
{
public:
    Complex()
    {
        mReal = 0.0;
        mImag = 0.0;
    }
    Complex(double aReal)
    {
        mReal = aReal;
        mImag = 0.0;
    }
    Complex(double aReal, double aImag)
    {
        mReal = aReal;
        mImag = aImag;
    }
    void setReal(const double& aReal)
    {
        mReal = aReal;
    }
    const double& getReal() const
    {
        return mReal;
    }
    void setImag(const double& aImag)
    {
        mImag = aImag;
    }
    const double& getImag() const
    {
        return mImag;
    }
    void display() const;
private:
    double mReal;   //复数的实部
    double mImag;   //复数的虚部
};

void Complex::display() const
{
    cout << mReal << " + " << mImag << "i";
}

Complex operator+(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    comp.setReal(aComplex1.getReal() + aComplex2.getReal());
    comp.setImag(aComplex1.getImag() + aComplex2.getImag());
    return comp;
}

Complex operator-(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    comp.setReal(aComplex1.getReal() - aComplex2.getReal());
    comp.setImag(aComplex1.getImag() - aComplex2.getImag());
    return comp;
}

Complex operator*(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    double real = aComplex1.getReal() * aComplex2.getReal() - aComplex1.getImag() * aComplex2.getImag();
    comp.setReal(real);
    double imag = aComplex1.getImag() * aComplex2.getReal() + aComplex1.getReal() * aComplex2.getImag();
    comp.setImag(imag);
    return comp;
}

Complex operator/(const Complex& aComplex1, const Complex& aComplex2)
{
    Complex comp;
    double square = aComplex2.getReal() * aComplex2.getReal() + aComplex2.getImag() * aComplex2.getImag();
    double real = (aComplex1.getReal() * aComplex2.getReal() + aComplex1.getImag() * aComplex2.getImag()) / square;
    comp.setReal(real);
    double imag = (aComplex1.getImag() * aComplex2.getReal() - aComplex1.getReal() * aComplex2.getImag()) / square;
    comp.setImag(imag);
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
