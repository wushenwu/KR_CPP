#include <iostream>
using namespace std;

#include <math.h>

#include "float.h"

int CFloat::m_nprecision = 0;

void
CFloat::SetPrecision(int nprecision)
{
    m_nprecision = nprecision;
}

void 
CFloat::PrintData(void (*pfnprint)(int, int))
{
    pfnprint(m_nint, m_ndecimal);
}

void
CFloat::SetFloat(float fdata)
{
    int nint = (int)fdata;
    int ndecimal = (fdata - float(nint)) * pow(10, m_nprecision);

    SetFloat(nint, ndecimal);
}

void 
CFloat::SetFloat(int nint, int ndecimal)
{
    m_nint = nint;
    m_ndecimal = ndecimal;
}
