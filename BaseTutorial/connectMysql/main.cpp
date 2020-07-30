#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main()
{
    MYSQL conn;
    mysql_init(&conn);
    auto connRet = mysql_real_connect(&conn, nullptr, "root", "123456", "anytalk_database", 3306, nullptr, 0);
    if (connRet != nullptr)
    {
        cout << "connect OK!" << endl;
    }
    return 0;
}
