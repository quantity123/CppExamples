#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ids[] = {0, 1, 2, 3, 4, 5};
    for (auto v : ids)
    {
        cout << v << " ";
    }
    cout << endl;

    for (int i=0; i<sizeof(ids)/sizeof(int); i++)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> iGroup;
    for (int i=0; i<5; i++)
        iGroup.push_back(i);
    for (const auto& v : iGroup)   //第一快的for循环
        cout << v << " ";
    cout << endl;
    for (vector<int>::const_iterator iter=iGroup.begin(); iter!=iGroup.end(); iter++)   //第二快的for循环
        cout << *iter << " ";
    cout << endl;
    for (vector<int>::size_type i=0; i<iGroup.size(); i++)
        cout << iGroup[i] << " ";
    cout << endl;
    return 0;
}
