#include <iostream>
using namespace std;

#include "writer.h"

#ifndef USE_MYSTRING

CPerson::CPerson()
{
    Init(&m_pstrname);
}

CPerson::CPerson(const char *pszname)
{
    Init(&m_pstrname);
    SetName(pszname);
}

CPerson::CPerson(const CPerson &obj)
{
    Init(&m_pstrname);
    SetName(obj.m_pstrname);
}

CPerson::~CPerson()
{
    Release(&m_pstrname);
}

void
CPerson::SetName(const char *pszname)
{
    Release(&m_pstrname);
    SetData(&m_pstrname, pszname);
}

void 
CPerson::Init(char **pdst)
{
    *pdst = NULL;
}

void 
CPerson::SetData(char **ppdst, const char *psrc)
{
    if (NULL == psrc)
    {
        return;
    }

    *ppdst = new char[strlen(psrc) + 1];
    if ( *ppdst != NULL)
    {
        strcpy(*ppdst, psrc);
    }
}

void 
CPerson::Release(char **pdst)
{
    if ( *pdst != NULL)
    {
        delete[] *pdst;
        *pdst = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////
///CWriter
//////////////////////////////////////////////////////////////////////////
CWriter::CWriter()
{
    Init(&m_pstrsign);
}

CWriter::CWriter(const char *pszname, const char *pszsign)
{
    Init(&m_pstrsign);
    SetName(pszname, pszsign);
}

CWriter::CWriter(const CWriter &obj)
{
    Init(&m_pstrsign);
    SetName(obj.m_pstrname, obj.m_pstrsign);
}

CWriter::~CWriter()
{
    //只负责本类内新增的资源
    Release(&m_pstrsign);
}

void
CWriter::SetName(const char *pszname, const char *pszsign)
{
    CPerson::SetName(pszname);  

    Release(&m_pstrsign);
    SetData(&m_pstrsign, pszsign);
}


#endif

void
CPerson::SayName() const
{
    if (m_pstrname != NULL)
    {
        cout << "Person Name: " << m_pstrname << endl;
    }
}

void
CWriter::SayName() const
{
    if (m_pstrname != NULL)
    {
        cout << "Writer Name: " << m_pstrname << endl;
    }

    if (m_pstrsign != NULL)
    {
        cout << "  signname: " << m_pstrsign << endl;
    }         
}
