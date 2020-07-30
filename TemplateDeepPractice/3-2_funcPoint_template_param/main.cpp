#include "funcPointTemplate.h"

using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    foreach<int, print<int>>(array, 6);
    cout << endl;

    foreach<int, inc<int>>(array, 6);
    foreach<int, print<int>>(array, 6);
    cout << endl;

    foreach<int, dec<int>>(array, 6);
    foreach<int, print<int>>(array, 6);
    cout << endl;
    return 0;
}
