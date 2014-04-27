/************************************************************************/
/* 3.使用重载完成两数交换函数                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

void
exchange(int &n1, int &n2)
{
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void
exchange(float &f1, float &f2)
{
    float tmp = f1;
    f1 = f2;
    f2 = tmp;
}

int
main(void)
{
    int n1 = 33, n2 = 15;
    float f1 = 33.3f, f2 = 15.5f;
    double d1 = 33.3, d2 = 15.5;

    cout << n1 << " " << n2 << endl;
    exchange(n1, n2);
    cout << n1 << " " << n2 << endl;

    cout << f1 << " " << f2 << endl;
    exchange(f1, f2);
    cout << f1 << " " << f2 << endl;

    return 0;
}