#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <deque>

using namespace std;

class Name
{
private:
    string first;
    string second;
public:
    Name(const string& name1, const string& name2)
        : first(name1), second(name2)
    {
    };
    Name() = default;
    string GetFirst() const
    {
        return first;
    }
    string GetSecond() const
    {
        return second;
    }
    friend istream& operator>>(istream& in, Name& name);
    friend ostream& operator<<(ostream& out, const Name& name);
};

istream& operator>>(istream& in, Name& name)
{
    return in >> name.first >> name.second;
}

ostream& operator<<(ostream& out, const Name& name)
{
    return out << name.first << " " << name.second;
}

int main()
{
    vector<int> numbers{99, 77, 33, 66, 22, 11, 44, 88};

    sort(begin(numbers), end(numbers)); //默认升序
    copy(begin(numbers), end(numbers), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(begin(numbers), end(numbers), greater<int>()); //降序greater<int>(), 升序less<int>(), 小于等于less_equal<type>(), 大于等于gtater_equal<type>()
    copy(begin(numbers), end(numbers), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<string> words{"one", "two", "nine", "nine", "one", "three", "four", "five", "six"};
    auto SortCompare(
        [](const string& s1, const string& s2)
        {
            return s1.back() > s2.back();
        }
    );
    sort(begin(words), end(words), SortCompare);
    copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
    cout << endl;

    vector<Name> names;
    cout << "Enter names as first name followed by second name. Enter Ctrl+Z to end:";
    copy(istream_iterator<Name>(cin), istream_iterator<Name>(), back_insert_iterator<vector<Name>>(names));
    cout << names.size() << " names read. Sorting in ascending sequence..." << endl;
    auto NameCompare = [](const Name& name1, const Name& name2)
    {
        return name1.GetSecond() < name2.GetSecond();
    };
    sort(begin(names), end(names), NameCompare);
    cout << "The names in ascending sequence are: " << endl;
    copy(begin(names), end(names), ostream_iterator<Name>(cout, "\n"));
    return 0;
}
