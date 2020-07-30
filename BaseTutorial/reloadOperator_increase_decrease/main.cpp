#include <iostream>
#include <iomanip>

using namespace std;

class StopWatch
{
public:
    StopWatch();
    void setZero();
    StopWatch run();    //调用原始 ++ 操作符
    StopWatch operator++(); // ++i
    StopWatch operator++(int);  // i++
    friend ostream& operator<<(ostream&, const StopWatch&);
private:
    int mMin;    //分钟
    int mSec;    //秒钟
};

StopWatch::StopWatch()
{
    mMin = 0;
    mSec = 0;
}

void StopWatch::setZero()
{
    mMin = 0;
    mSec = 0;
}

StopWatch StopWatch::run()    //调用原始 ++ 操作符
{
    ++mSec;
    if (mSec == 60)
    {
        mMin++;
        mSec = 0;
    }
    return *this;
}

StopWatch StopWatch::operator++()   // ++i
{
    return run();
}

StopWatch StopWatch::operator++(int)  // i++
{
    StopWatch sw = *this;
    run();
    return sw;
}

ostream& operator<<(ostream& aOut, const StopWatch& aS)
{
    aOut << setfill('0') << setw(3) << aS.mMin << ":" << setw(3) << aS.mSec;
    return aOut;
}

int main()
{
    StopWatch s1, s2;

    s1 = s2++;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    s1.setZero();
    s2.setZero();
    cout << "setZero()" << endl;
    s1 = ++s2;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    return 0;
}
