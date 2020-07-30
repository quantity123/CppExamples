#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    cout << "Enter numeric values separated by spaces and enter Ctrl+Z to end:" << endl;
    cout << "The sum of the values you entered is " << accumulate(istream_iterator<double>(cin), istream_iterator<double>(), 0.0) << endl;
    return 0;
}
