/************************************************************************/
/* 3.	��1��10��10������ȡ��3����ͬ���������ж�������Ϸ�ʽ���㷨��ʹ����ѧ�е���Ϲ�ʽ������m=10,n=3��
pn^m=[n/(n-m)]p(n-1)^m   (n,m ����n������m����n) 
pn^m=n!/(n-m)!      (n,m����n,    ����m������n;��m=nʱ��0��=1��      

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