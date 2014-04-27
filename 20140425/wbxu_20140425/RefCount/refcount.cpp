#include <iostream>
using namespace std;

#include "refcount.h"

#ifdef STATIC

int CStudent::m_nrefcount = 0;

#endif

void
CStudent::AddRef(void)
{
#ifdef STATIC
    m_nrefcount++;
#else
    *m_prefcount = *m_prefcount + 1;
#endif
}

void
CStudent::Release(void)
{
#ifdef STATIC
    if (0 == --m_nrefcount)
#else
    if (NULL == m_prefcount)
    {
        return;
    }

    if (0 == --*m_prefcount)
#endif
    {
        if (m_pszname)
        {
            delete[] m_pszname;
            m_pszname = NULL;
        }
    
    #ifndef STATIC
        delete m_prefcount;     //������������Ϊһ����Դ��Ҳ��Ҫ�ͷ�
        m_prefcount = NULL;
    #endif

    }
}

CStudent::CStudent()
{
    m_no = 0;
    m_pszname = NULL;

#ifndef STATIC
    m_prefcount = NULL;
#endif
}

CStudent::CStudent(int no, char *pszname)
{
    SetNo(no);
    SetName(pszname);   //��������Դ, ���������ü�������
}

CStudent::CStudent(const CStudent &stud)
{
    SetNo(stud.m_no);
    //SetName(stud.m_pszname);

    //����ǳ�������������ü���������Դ���й���
    m_pszname = stud.m_pszname; 

#ifndef STATIC
    m_prefcount = stud.m_prefcount;
#endif

    AddRef();
}

void 
CStudent::SetName(const char *pszname)
{
    m_pszname = new char[strlen(pszname) + 1];
    if (m_pszname)
    {
        strcpy(m_pszname, pszname);

    #ifndef STATIC
        //������������Ϊһ����Դ����Ҫ��������.
        //�ҽ����µ���Դ����ʱ
        m_prefcount = new int;  
        *m_prefcount = 0;
    #endif

        AddRef();   //
    }
}

void
CStudent::SetNo(int no)
{
    m_no = no;
}

const char *
CStudent::GetName(void) const
{
    return m_pszname;
}

int
CStudent::GetNo(void) const
{
    return m_no;
}

void 
CStudent::init(int no)
{
    m_no = no;
}


CStudent::~CStudent()
{
//     if (m_pszname)
//     {
//         delete[] m_pszname;
//         m_pszname = NULL;
//     }

    //�������ü������Ӽ������ȷ���ͷ����
    Release();

    m_no = 0;
}

