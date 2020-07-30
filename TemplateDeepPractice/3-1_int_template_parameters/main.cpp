#include <iostream>
#include "IntTemplateParam.h"

using namespace std;

int main()
{
    Array<char, 20> array0;
    Array<char, 10> array1; //与上面数组长度不同
    array0[10] = 'b';
    try
    {
        array1[10] = 'c';
    } catch (out_of_range& e)   //捕获异常
    {
        cerr << e.what() << endl;   //处理显示异常信息
    }
    return 0;
}
