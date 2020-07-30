#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const vector<int> vint(3, 1);
    for (auto i : vint)
        cout << i << endl;

    vector<string> v1(3, "hi2");
    for (auto s : v1)
        cout << s << endl;

    vector<int> vi;
    for (auto i=0; i<10; i++)
    {
        vi.push_back(i);
    }
    for (auto i : vi)
        cout << i << endl;

    return 0;
}
