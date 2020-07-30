#ifndef PARSEMESSAGE_H
#define PARSEMESSAGE_H

#include <string>
#include <iostream>

using namespace std;

class parseMessage
{
};


//bool parseMessage2(const string& input, int* type, string& outBuffer);

bool parseMessage2(const string& input, int* type, string& outBuffer)
{
    cout << input << ", " << *type << ", " << outBuffer << endl;
    return true;
}


#endif // PARSEMESSAGE_H
