#include <iostream>
#include "List.hpp"

using namespace std;

int main()
{
    List<char> l;
    l.pushFront('a');
    cout << *l.begin() << endl;
    return 0;
}
