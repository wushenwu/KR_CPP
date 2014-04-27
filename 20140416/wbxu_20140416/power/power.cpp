/************************************************************************/
/* 2.写一个函数power(double x, int n)，其返回值为x的n次方，并用此函数计算1.5 3。                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include <math.h>

double
power(double x, int n)
{
    int i = 0;
    double dresult = 1.0;

    while (i < n)
    {
        dresult *= x;

        i++;
    }

    return dresult;    
}

int
main(void)
{
    cout << "by pow" << pow(1.5, 3) << endl;
    cout << "by mypower " << power(1.5, 3) << endl;
    return 0;
}