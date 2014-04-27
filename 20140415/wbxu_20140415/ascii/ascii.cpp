/************************************************************************/
/* 2.用C++将Ascii码表(分别以十进制，字符，十六进制,八进制)输出控制台上。                                                                     */
/************************************************************************/

#include <iostream.h>
//#include <ctype.h>   isprint

int
main(void)
{
    int i = 0;
    
    for (i = 0; i < 128; i++)
    {
        //cout.flags(nflag);
        cout << (char)i
             << " dec:" << dec << i
             << " hex:" << hex << i
             << " oct:" << oct << i
             << " " << endl;
    }

    return 0;
}