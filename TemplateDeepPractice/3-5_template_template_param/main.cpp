#include <iostream>
#include "template_In_template.h"

using namespace std;

int main()
{
    int array[]{1, 2, 3, 4, 5, 6};

    foreach<int, print>(array, 6);
    //foreach<print>(array, 6); 如果foreach的模板第一个参数放末尾，则可以这样调用，默认类型由第一个参数来推导
    cout << endl;

    foreach<int, inc>(array, 6);
    foreach<int, print>(array, 6);
    cout << endl;

    foreach<int, cdec>(array, 6);
    foreach<int, print>(array, 6);
    cout << endl;
    return 0;
}
