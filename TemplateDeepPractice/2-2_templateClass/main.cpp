#include "stack.hpp"
#include "classtemplate.hpp"

using namespace std;

int main()
{
    countStack<int> cs;
    cs.push(1);
    cs.push(2);
    cout << "getSize: " << cs.getSize() << endl;
    cout << "isEmpty: " << cs.empty() << endl;
    cout<< "top: " << cs.top() << endl;
    cs.pop();
    cout << "pop()" << endl;
    cout << "getSize: " << cs.getSize() << endl;


    ClassTemplate<int> t;
    t.set<int>(100);
    auto v = t.get<int>();
    cout << "ClassTemplate::get: " << v << endl;

    return 0;
}
