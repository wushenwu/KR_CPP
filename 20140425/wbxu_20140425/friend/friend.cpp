#include <iostream>
using namespace std;

#include "friend.h"

/*
该成员函数已被声明为CStudent的友元函数，所以，可以访问其私有成员
*/
void
COther::func(void)
{
    CStudent stud;
    stud.m_no = 0x1234;

    stud.init(0x5678);

    //当然了，更有效地例子是，func(CStudent &object)，在func中对object进行修改
    //但考虑到它们间的相互依赖，目前无法解决
}

/*
 在CStudent的构造被设置为私有，正常途径无法创建对象的情况下，
    通过该友元成员函数，可以创建CStudent对象。
    这里函数的实现，使得对象仅能产生在堆上。
*/
CStudent *
COther::CreateObject(void)
{
    return new CStudent();
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
        free(m_pszname);
        m_pszname = NULL;
    }

    m_no = 0;
}

void
CStudent::KillMe(void)
{
    delete this;
}
