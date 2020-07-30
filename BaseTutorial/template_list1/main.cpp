#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> str;

    str.insert(str.begin(), "bbb");
    str.push_back("ccc");
    str.push_front("aaa");
    str.insert(str.end(), "ddd");
    //list<string>::iterator iter;
    list<string>::const_iterator iter;  //常量的迭代器，只读。
    for (iter=str.begin(); iter != str.end(); iter++)
    {
        cout << *iter << endl;
    }
    str.reverse();
    for (iter=str.begin(); iter != str.end(); iter++)
    {
        cout << *iter << endl;
    }

    list<string>* pstr = new list<string>;
    pstr->push_back("paaa");
    pstr->push_back("pbbb");
    list<string>::iterator iter2;
    for (iter2=pstr->begin(); iter2 != pstr->end(); iter2++)
    {
        cout << *iter2 << endl;
    }
    delete pstr;
    return 0;
}
