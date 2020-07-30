#include <iostream>

using namespace std;

template<class T, int S>
class Array
{
public:
    Array();
    ~Array();
    T& operator[](int aI);
    const T& operator[](int aI) const;
    int getLen() const;
private:
    int mLength;
    T* mNum;
};

template<class T, int S>
Array<T, S>::Array()
{
    mNum = new T[S];
    mLength = S;
}

template<class T, int S>
Array<T, S>::~Array()
{
    delete[] mNum;
}

template<class T, int S>
T& Array<T, S>::operator[](int aI)
{
    if (aI < 0 || aI >= mLength)
        throw string("out of bounds");
    return mNum[aI];
}

template<class T, int S>
const T& Array<T, S>::operator[](int aI) const
{
    if (aI < 0 || aI >= mLength)
        throw string("out of bounds");
    return mNum[aI];
}

template<class T, int S>
int Array<T, S>::getLen() const
{
    return mLength;
}

template<class T, int S>
ostream& operator<<(ostream& aOut, const Array<T, S>& aA)
{
    for (int i=0; i<aA.getLen(); i++)
    {
        aOut << aA[i] << endl;
    }
    return aOut;
}

int main()
{
    Array<int, 10> arr;
    for (int i=0; i<10; i++)
    {
        arr[i] = 2 * i;
    }
    cout << arr << endl;
    return 0;
}
