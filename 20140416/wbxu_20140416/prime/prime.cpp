/************************************************************************/
/* 1.写一个函数int prime(int x)，如果x是素数返回值为1，否则返回0。并用主函数验证它。                                                                      */
/************************************************************************/

#include <iostream>
using namespace std;

#include <math.h>

int
prime(int x)
{
    int ilimit = 0;
    int result = 1;     //suppose it is prime
    int i = 0;

    ilimit = sqrt(x);

    for (i = 2; i <= ilimit; i++)
    {
        if (0 == x % i)
        {
            result = 0;     //now it can be divided, so not.
            break;
        }
    }

    return result;
}

int
main(void)
{
    int num = 13;
    int result = 0;

    cin >> num;
    cout << "num: " << num;
    result = prime(num);
    if (1 == result)
    {
       cout <<  " is a prime" << endl;
    }
    else
    {
        cout << "is not a prime" << endl;
    }

    return 0;
}