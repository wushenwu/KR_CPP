#include <string.h>
#include "const.h"

CConst::CConst()
{
    init(0, NULL);
}
CConst::CConst(int n1, char *psz)   //just 4 fun, should use const though
{
    init(n1, psz);
}

CConst::CConst(const CConst &object)
{
    init(object.m_n1, object.m_psz);
}

CConst::~CConst()
{
    if (m_psz)
    {
        delete[] m_psz
    }

    m_psz = NULL;
    m_n1 = 0;
}

void
CConst::init(int n1, char *psz)
{
    m_n1 = n1;
    
    //ugly, just 4 fun
    if (psz)
    {
        m_psz = new char[strlen(psz) + 1];

        strcpy(m_psz, psz);
    }
    else
    {
        m_psz = NULL;
    }
}

void
CConst::SetNum1(int n1)
{
    //char *pch = this;   //强制出错。一般的，this指针类型为class Cxx *const
    m_n1 = n1;
}

int
CConst::GetNum1() const
{
    //char *pch = this; //强制出错,爆出this指针的类型, 
                      //常成员函数的this指针类型为 const class Cxx *const

    ((CConst *const)this)->m_n1 = 0x8888;   //将this指针进行强制类型转换，予以突破
                    
    return m_n1;
}

#ifndef CONST

char *
CConst::GetName(void) const     //这样，仍然无法限制类对象修改数据成员
{
    return m_psz;
}

#else

const char *
CConst::GetName(void) const    //用const 对返回类型进行限制
{
    return m_psz;
}

#endif

void
CConst::SetName(const char *pszname)
{
    strcpy(m_psz, pszname);
}