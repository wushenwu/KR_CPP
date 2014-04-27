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
    //char *pch = this;   //ǿ�Ƴ���һ��ģ�thisָ������Ϊclass Cxx *const
    m_n1 = n1;
}

int
CConst::GetNum1() const
{
    //char *pch = this; //ǿ�Ƴ���,����thisָ�������, 
                      //����Ա������thisָ������Ϊ const class Cxx *const

    ((CConst *const)this)->m_n1 = 0x8888;   //��thisָ�����ǿ������ת��������ͻ��
                    
    return m_n1;
}

#ifndef CONST

char *
CConst::GetName(void) const     //��������Ȼ�޷�����������޸����ݳ�Ա
{
    return m_psz;
}

#else

const char *
CConst::GetName(void) const    //��const �Է������ͽ�������
{
    return m_psz;
}

#endif

void
CConst::SetName(const char *pszname)
{
    strcpy(m_psz, pszname);
}