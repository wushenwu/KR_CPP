/************************************************************************/
/* 2.写一整型基类Integer里只含一整型数据，和一加法成员方法Integer* Add(Integer *num)，
然后写其子类Float使其多一成员即来表示小数点后的数据。
写main函数实现Float的加法运算，并举例输出(其中类里要提供自己的输出方法)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include <math.h>

#include "float.h"

void FunPrintData(int nint, int ndecimal)
{
    cout << nint << "." << ndecimal << endl;
}

void
test_float(void)
{
    CFloat fdata;
    float ftest = 3.14159267890f;

    CFloat::SetPrecision(6);
    fdata.SetFloat(ftest);
    fdata.PrintData(FunPrintData);

    int nflg = cout.setf(ios::fixed);
    int nprecision = cout.precision(6);
    cout << ftest << endl;
    cout.precision(nprecision);
    cout.setf(nflg);
}

void
test_add(void)
{
    CFloat f1, f2;
    float ftest = 3.14159267890f;

    int nprecision = 6;
    CFloat::SetPrecision(nprecision);

    f1.SetFloat(ftest);
    f2.SetFloat(ftest);


    f1.Add(&f2)->PrintData(FunPrintData);

    int nflg = cout.setf(ios::fixed);
    nprecision = cout.precision(6);
    cout << ftest + ftest << endl;
    cout.precision(nprecision);
    cout.setf(nflg);
}

int
main(void)
{
    test_float();

    test_add();

    return 0;
}