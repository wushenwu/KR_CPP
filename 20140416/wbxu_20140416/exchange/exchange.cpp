#include <iostream>
using namespace std;

void
exchange_by_ptr(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void
exchange_by_ref(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int
main(void)
{
    int n = 33;
    int m = 17;

    cout << "n = " << n << " m = " << m << endl;

    exchange_by_ptr(&n, &m);
    cout << "by ptr       n = " << n << " m = " << m << endl;

    exchange_by_ref(n, m);
    cout << "by reference n = " << n << " m = " << m << endl;

    return 0;
}