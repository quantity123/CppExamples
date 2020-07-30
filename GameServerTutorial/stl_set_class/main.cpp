#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person
{
private:
    string mName;
    int mAge;
public:
    Person(string aName, int aAge);
    int getAge() const;
    const string& getName() const;
    void print() const;
    bool operator==(const Person& rhs) const;
};

Person::Person(string aName, int aAge)
{
    mName = aName;
    mAge = aAge;
}

bool Person::operator==(const Person& aComparePerson) const
{
    return (aComparePerson.mName == mName) && (aComparePerson.mAge == mAge);
}

int Person::getAge() const
{
    return mAge;
}


const string& Person::getName() const
{
    return mName;
}


void Person::print() const
{
    cout << mName << ":" << mAge << endl;
}

class CompareName
{
public:
    template<typename T>
    bool operator()(const T& t1, const T& t2) const
    {
        return t1.getName() < t2.getName();
    }
};

struct CompareAge   //struct 和 claas publice 都可以被 set容器使用
{
    template<typename T>
    bool operator()(const T& t1, const T& t2) const
    {
        return t1.getAge() < t2.getAge();
    }
};

int main()
{
    Person p1("Alice", 23);
    Person p2("Bob", 16);
    Person p3("Camily", 18);

    using PersonSetCompareName = set<Person, CompareName>;
    PersonSetCompareName nameOrder;
    nameOrder.insert(p1);
    nameOrder.insert(p2);
    nameOrder.insert(p3);
    for (auto& v: nameOrder)
    {
        v.print();
    }
    cout << endl;

    using PersonSetCompareAge = set<Person, CompareAge>;
    PersonSetCompareAge ageOrder;
    ageOrder.insert(p1);
    ageOrder.insert(p2);
    ageOrder.insert(p3);
    for (auto& v: ageOrder)
    {
        v.print();
    }
    cout << endl;

    Person p4("qtt", 23);

    auto iter = nameOrder.find(p4);
    if (iter == nameOrder.end())
    {
        cout << "p4 name not in nameOrder" << endl;
    }
    else
    {
        cout << "p4 name in nameOrder" << endl;
    }

    iter = ageOrder.find(p4);
    if (iter == ageOrder.end())
    {
        cout << "p4 age not in nameOrder" << endl;
    }
    else
    {
        cout << "p4 age in nameOrder" << endl;
    }
    cout << endl;

    Person p5("qtt", 23);

    if (p4 == p5)   //Person类重载了==判断相等操作符，所以可以Person类型直接==相等判断，否则报错
        cout << "p4 == p5" << endl;
    else
        cout << "p4 != p5" << endl;
    return 0;
}
