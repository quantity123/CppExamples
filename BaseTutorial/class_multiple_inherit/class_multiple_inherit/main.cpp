#include <iostream>

using namespace std;

class Teacher
{
public:
    void setTitle(const string aTitle);
    const string getTitle() const;
private:
    string mTitle;  //职称
};

void Teacher::setTitle(const string aTitle)
{
    mTitle = aTitle;
}

const string Teacher::getTitle() const
{
    return mTitle;
}

class Cadre
{
public:
    void setPost(const string aPost);
    const string getPost() const;
private:
    string mPost;
};

void Cadre::setPost(const string aPost)
{
    mPost = aPost;
}

const string Cadre::getPost() const
{
    return mPost;
}

class Teacher_Cadre: public Teacher, public Cadre
{
public:
    void setSalary(const unsigned& aSalary);
    const unsigned& getSalary() const;
private:
    unsigned mSalary;
};

void Teacher_Cadre::setSalary(const unsigned& aSalary)
{
    mSalary = aSalary;
}

const unsigned& Teacher_Cadre::getSalary() const
{
    return mSalary;
}

int main()
{
    Teacher_Cadre* tc = new Teacher_Cadre;
    tc->setTitle("c++ teather");
    tc->setPost("leader");
    tc->setSalary(30000);
    cout << "teacher:" << tc->getTitle() << ", post:" << tc->getPost() << ", salary:" << tc->getSalary() << endl;
    delete tc;
    return 0;
}
