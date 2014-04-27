#include <iostream>
using namespace std;

int
main(void)
{
    char szbuf[8];

    cin.read(szbuf, 7);
    szbuf[7] = '\0';

    //清除缓冲区或者直到遇到指定的字符
    cin.ignore(cin.rdbuf()->in_avail(),     //缓冲区中剩余的个数
                '\n');

    //
    cin.getline(szbuf,
                 8,         //包含\0 的总数目
                 '\n');
    
    return 0;
}