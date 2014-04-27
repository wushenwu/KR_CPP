#include <iostream>
using namespace std;

#include "student.h"

CStudent::CStudent()
{
    //
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
    m_pszname = (char *)malloc(strlen(pszname) + 1);
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
CStudent::GetName(void)
{
    return m_pszname;
}

int
CStudent::GetNo(void)
{
    return m_no;
}

CStudent::~CStudent()
{
    if (m_pszname)
    {
        free(m_pszname);
        m_pszname = NULL;
    }
}
