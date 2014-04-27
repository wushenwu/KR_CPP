#include <iostream>
using namespace std;

#include "limits.h"
#include "float.h"

void
showdata(CFloat &ftest)
{
    cout << ftest.GetInt() << ".";

    long nflag = cout.flags(ios::right);
    cout.width(10);
    cout.fill('0');
    cout << ftest.GetFract() << endl;

    cout.flags(nflag);
}

void
test_float(void)
{
    CFloat ftest1;
    ftest1.SetFloat(3, 14);    
    showdata(ftest1);

    CFloat ftest2;   
    ftest2.SetFloat(3, 14);
    showdata(ftest2);

    CFloat fsum;
    fsum = fsum.AddFloat(ftest1, ftest2);
    showdata(fsum);
}

int
main(void)
{
    test_float();

    return 0;
}