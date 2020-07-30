#include "MutilTemplate.hpp"

using namespace std;

int main()
{
    S<float, float, float> s1;  //与特例都不匹配，所以用通例匹配
    cout << s1.id() << endl;
    S<int, int, int> s2;        //只能与特例3匹配
    cout << s2.id() << endl;
    S<int, int, char> s3;       //只能与特例1匹配，与特例3本来匹配，但是第二和第三参数类型必须相同
    cout << s3.id() << endl;
    S<char, char, char> s4;     //特例1和特例2都匹配，但是选择了特例2，因为特例2有两个char参数，所以更加匹配
    cout << s4.id() << endl;
    //S<int, char, char> s5;    //报错，匹配有歧义,特例2和特例3匹配太接近，所以有冲突，分辨不出谁更特殊
    //cout << s5.id() << endl;
    return 0;
}
