/************************************************************************/
/* 2.дһ���ͻ���Integer��ֻ��һ�������ݣ���һ�ӷ���Ա����Integer* Add(Integer *num)��
Ȼ��д������Floatʹ���һ��Ա������ʾС���������ݡ�
дmain����ʵ��Float�ļӷ����㣬���������(��������Ҫ�ṩ�Լ����������)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include <math.h>

#include "float.h"

void PrintData(int nint, int ndecimal)
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
    fdata.PrintData(PrintData);

    int nflg = cout.setf(ios::fixed);
    int nprecision = cout.precision(6);
    cout << ftest << endl;
    cout.precision(nprecision);
    cout.setf(nflg);
}

void
test_add(void)
{
    CFloat f1, f2, fsum;
    float ftest = 3.14159267890f;

    int nprecision = 6;
    CFloat::SetPrecision(nprecision);

    f1.SetFloat(ftest);
    f2.SetFloat(ftest);

    int nint = f1.Add(&(f2.GetInt()))->GetData();

    int ndecimal = (f1.GetDecimal()).Add(&(f2.GetDecimal()))->GetData();
  
    int nmax = pow(10, nprecision + 1);
    if (ndecimal >= nmax)
    {
        ndecimal -= nmax;
        nint += 1;
    }

    fsum.SetFloat(nint, ndecimal);
    fsum.PrintData(PrintData);

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