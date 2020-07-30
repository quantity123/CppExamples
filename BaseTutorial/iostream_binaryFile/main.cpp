#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int A[3][10] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {1, 2, 3, 4, 7, 7, 7, 7, 9, 9}, {5, 3, 8, 0, 4, 4, 4, 8, 8, 8}};
    int B[3][10];
    int i, j;

    for (i=0; i<3; i++)
    {
        for (j=0; j<10; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

//把数据写入test.txt文件********************************************************************

    ofstream output("test.txt", ios::out | ios::binary);
    if (!output)
    {
        cerr << "Open output file error." << endl;
        exit(-1);
    }

    char* pA = reinterpret_cast<char*>(&A);
    output.write(pA, sizeof(A));    //一次性写入输出文件流
    //循环单个写入输出文件流
    for (i=0; i<3; i++)
    {
        for (j=0; j<10; j++)
        {
            /*
            char* pChar = reinterpret_cast<char*>(&A[i][j]);
            output.write(pChar, sizeof(A[i][j]));
            */
        }
    }
    output.close();

//把数据从test.txt文件里读出*********************************************************************

    ifstream input("test.txt", ios::in | ios::binary);
    if (!input)
    {
        cerr << "Open input file error!" << endl;
        exit(-1);
    }

    char* pB = reinterpret_cast<char*>(&B);
    input.read(pB, sizeof(B));  //一次性读出输入文件流
    //循环单个读出输入文件流
    for (i=0; i<3; i++)
    {
        for (j=0; j<10; j++)
        {
            //char* pChar = reinterpret_cast<char*>(&B[i][j]);
            //input.read(pChar, sizeof(B[i][j]));
        }
    }
    for (i=0; i<3; i++)
    {
        for (j=0; j<10; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //将文件读写指针移动到指定位置并操作其中的数据
    int temp;
    input.seekg(20*sizeof(int), ios::beg);  //第一个参数是移动的大小长度，第二个参数是从哪个位置开始的 beg文件开头，cur文件当前位置，end文件结尾
    char* pTemp = reinterpret_cast<char*>(&temp);
    input.read(pTemp, sizeof(temp));
    cout << temp << endl;

    return 0;
}
