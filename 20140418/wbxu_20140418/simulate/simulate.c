/************************************************************************/
/* 7.用C语言模拟C++的类语法                                                                      */
/************************************************************************/

#include <stdio.h>
#include "simulate.h"

#define MAX_INSTANCE   8

static void
SetData(tag_class *pself, int ndata)
{
   pself->m_ndata = ndata;
}

static int
GetData(tag_class *pself)
{
    return pself->m_ndata;
}

void
ClassInit(tag_class *pobject)
{
    pobject->pfnSetData = SetData;
    pobject->pfnGetData = GetData;    
}
