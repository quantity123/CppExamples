#include <iostream>

using namespace std;

class student
{
private:
    string name;
    int age;
public:
    void setName(string Aname);
    string getName();
    inline void set_age(int a)
    {
        age = a;
    }
    inline int get_age()
    {
        return age;
    }
};

void student::setName(string AName)
{
    name = AName;
}

string student::getName()
{
    return name;
}

int main()
{
    student sdt;
    sdt.set_age(20);
    cout << sdt.get_age() << endl;

    student *psdt;
    psdt = new student;
    psdt->setName("qtt");
    cout << psdt->getName() << endl;

    return 0;
}
