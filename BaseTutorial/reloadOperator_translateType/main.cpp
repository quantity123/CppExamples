#include <iostream>

using namespace std;

class Clock
{
public:
    Clock();
    Clock(unsigned aH, unsigned aM, unsigned aAP);
    operator unsigned();    //1.没有返回类型，但必须retrun返回类类型，只能作为类重载操作符使用，不能定层函数形式和类友元函数重载。
private:
    unsigned mHour;
    unsigned mMin;
    unsigned mAP;
};

Clock::Clock()
{
    mHour = 0;
    mMin = 0;
    mAP = 0;
}

Clock::Clock(unsigned aH, unsigned aM, unsigned aAP)
{
    mHour = aH;
    mMin = aM;
    mAP = aAP;
}

Clock::operator unsigned()
{
    unsigned time = mHour;
    if (time == 12)
        time = 0;
    if (mAP == 1)
        time += 12;
    time *= 100;
    time += mMin;
    return time;
}

int main()
{
    Clock c(5, 7, 1);
    unsigned time = c;
    cout << time << endl;
    return 0;
}
