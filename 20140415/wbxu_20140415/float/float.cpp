/************************************************************************/
/* 4.用cout 输出float类型的整型形式。
5.用cout 输出类似printf("%d", 浮点数)格式化浮点为整形的方式
6.将2.45分别以整型，单(双)精度浮点,科学表示法输出 
                                                                    */
/************************************************************************/

#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>

void
showbytes(unsigned char *base, size_t size)
{
    unsigned int i = 0;
  
    for (i = 0; i < size; i++)
    {
        cout << hex << (int)*(base + i);
    }

    cout << endl;    
}

void
t4(void)
{
    float ftest = 343888888.1415926f;
    
    cout << (int)ftest << endl;
}

void
t5(void)
{
    float ftest = 3.1415926f;
    float ftmp  = 3.141593f;

    printf("%d\r\n", ftest);
    cout << *(int *)&ftest << endl;

    printf("%d\r\n", ftmp);
    cout << *(int *)&ftmp << endl;
}

void
t6(void)
{
//     int nold = cout.precision(1);
//     cout << "2.45: int " << 2.45 << endl;
//     cout.precision(nold);

    cout << "2.45: int " << (int)2.45 << endl;

    cout << "2.45: float" << (float)2.45 << endl;
    cout << "2.45: double" << (double)2.45 << endl;

    long nflg = cout.flags(ios::scientific);
    cout << 2.45 << endl;
    cout.flags(nflg);
}

int
main(void)
{
    t4();

    t5();

    t6();

    return 0;
}