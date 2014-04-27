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
        delete m_prefcount;     //计数器自身作为一种资源，也需要释放
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
    SetName(pszname);   //创建新资源, 并进行引用计数更新
}

CStudent::CStudent(const CStudent &stud)
{
    SetNo(stud.m_no);
    //SetName(stud.m_pszname);

    //进行浅拷贝，增加引用计数，对资源进行共享
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
        //计数器自身作为一种资源，需要进行申请.
        //且仅当新的资源产生时
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

    //更新引用计数，视计数情况确定释放与否
    Release();

    m_no = 0;
}

