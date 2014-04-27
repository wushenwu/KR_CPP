/************************************************************************/
/* 3.	求1到10共10个数中取出3个不同的数，共有多少种组合方式？算法：使用数学中的组合公式，其中m=10,n=3。
pn^m=[n/(n-m)]p(n-1)^m   (n,m 属于n，并且m不大n) 
pn^m=n!/(n-m)!      (n,m属于n,    并且m不大于n;当m=n时，0！=1）      

p(n,m) = n * (n - 1) * (n - 2)...* ( n - m + 1)
       = n * (n - 1) * (n - 2)...* ( n - m + 1) * (n - m )... * 1 / ( (n-m) * (n-m-1) ... * 1)
       = n! / (n-m)!
                                                               */
/************************************************************************/
#include <iostream>
using namespace std;

unsigned long
factor(int n)
{
    int i = 1;
    unsigned long result = 1;

    if (0 == n)
    {
        result = 1;
        return result;
    }

    while (i <= n)
    {
        result *= i;

        i++;
    }

    return result;
}

unsigned long
pselect(int n, int m)
{
    return factor(n) / factor(n - m);
}

int
main(void)
{
    int n = 10;
    int m = 3;

    cout << "Enter n, m" << endl;
    cin >> n;
    cin >> m;

    cout << pselect(n, m) << endl;

    return 0;
}