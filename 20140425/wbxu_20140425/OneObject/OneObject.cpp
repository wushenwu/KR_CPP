#include <iostream>
using namespace std;

#include "oneobject.h"

CStudent *
COther::CreateOjbect(void)
{
    return CStudent::CreateObject();
}

COther::~COther() 
{
    if (m_pstudobject)
    {
        m_pstudobject->~CStudent();
        m_pstudobject = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////

/*
仅能通过该接口创建对象，同时对象的创建被限定在了堆上
*/
CStudent *
CStudent::CreateObject(void)
{
    static CStudent *pojbect = new CStudent();
    
    return pojbect;
}

CStudent::CStudent()
{
    m_no = 0;
    m_pszname = NULL;
}

CStudent::CStudent(int no, char *pszname)
{
    SetNo(no);
    SetName(pszname);
}

CStudent::CStudent(const CStudent &stud)
{
    SetNo(stud.m_no);
    SetName(stud.m_pszname);
}

void 
CStudent::SetName(const char *pszname)
{
    m_pszname = new char [strlen(pszname) + 1];
    if (m_pszname)
    {
        strcpy(m_pszname, pszname);
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
    if (m_pszname)
    {
        delete[] m_pszname;
        m_pszname = NULL;
    }

    m_no = 0;
}

