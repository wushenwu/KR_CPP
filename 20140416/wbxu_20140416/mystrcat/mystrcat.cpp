/************************************************************************/
/* 0.дһ���ַ������ӹ��ܣ�ʹ�� const���β���
   8.MyStrCat() ��Ҫ��strcat                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

char *
mystrcat(char *szdst, const char *szsrc)
{
    char *psz = szdst;

    //come to the end of pszdst
    while (*psz)
    {
        psz++;
    }

    //cat pszsrc to pszdst
    while (*szsrc)
    {
        *psz = *szsrc;

        psz++;
        szsrc++;
    }

    //
    *psz = '\0';

    return szdst;
}

int
main(void)
{
    char szdst[64] = "hello world! ";
    char szsrc[32] = "Just 4 Fun\r\n";

    cout << "szdst: " << szdst << endl;
    cout << "szsrc: " << szsrc << endl;

    mystrcat(szdst, szsrc);

    cout << "szdst: " << szdst << endl;

    return 0;
}