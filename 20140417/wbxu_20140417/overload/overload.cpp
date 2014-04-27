#include <iostream>
using namespace std;

#if 0
int
test(int nvalue)
{
    return nvalue;
}

int
test(const int nvalue)
{
    return nvalue;
}

#else

int
test(int &nvalue)
{
    return nvalue;
}

int
test(const int &nvalue)
{
    return nvalue;
}

#endif

int
test(int *pnavalue)
{
    return *pnavalue;
}

//int 
//test(const int *pnavlue);   //?test@@YAHPBH@Z
//{
    //return *pnavlue;
//}

float
test(const int *pnavlue);   //?test@@YAMPBH@Z

int
main(void)
{
    int nvalue = 1;
    test(&nvalue);

    const int con_navlue = 1;
    test(&con_navlue);

    //test(&nvalue);

    return 0;
}