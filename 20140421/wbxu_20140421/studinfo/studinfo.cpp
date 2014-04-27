/************************************************************************/
/* 1.写一个学员信息录入程序，以学员信息类数组来放置录入的学员信息，并提供多种录入方式：
(1)学号和年龄为默认，学号默认为从1开始递增，年龄默认为20
(2)学号，姓名，年龄均不为默认,以学号和姓名来做为构造函数的参数(但要判断学号是唯一的,如果条件不符自己调用析构函数)
实现学员信息类的拷贝，(利用拷贝构造函数)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include <string.h>
#include "studinfo.h"

/*存储相关*/
static const int MAX_STUDENT = 10;
static CStudent g_arystud[MAX_STUDENT];  //这里会调用默认构造函数
static int g_ncount = 0;


//全局递增学号
static int g_studno = 0;

void
CStudent::SetName(const char *pszname)
{
#ifdef RESOURCE
    m_pszname = (char *)malloc(strlen(pszname) + 1);
    if (m_pszname)
    {
        strcpy(m_pszname, pszname);
    }
#else
    strncpy(m_szname, pszname, 64);
    m_szname[63] = '\0';
#endif
}

void
CStudent::SetNo(int no)
{
    m_no = no;
}

void
CStudent::SetAge(int nage)
{
    m_nage = nage;
}

const char *
CStudent::GetName(void)
{
#ifdef RESOURCE
    return m_pszname;
#else
    return m_szname;
#endif
}

int
CStudent::GetNo(void)
{
    return m_no;
}

int
CStudent::GetAge(void)
{
    return m_nage;
}

CStudent::CStudent()
{
    cout << "CStudent::CStudent()" << endl;
}

CStudent::CStudent(const char *pszname, int nage)
{
    cout << "CStudent::CStudent(char *, int)" << endl;

    SetName(pszname);

    SetNo(++g_studno);
    
    SetAge(nage);
}

CStudent::CStudent(int no, const char *pszname)
{
    cout << "CStudent::CStudent(int, const char *)" << endl;

    SetName(pszname);

    SetNo(no);     
}

CStudent::~CStudent()
{
    //在本题中，因类数组存储，故不能进行资源释放
#ifdef RESOURCE
    if (m_pszname)
    {
        free(m_pszname);
        m_pszname = NULL;
    }
#else


#endif
}

CStudent::CStudent(const CStudent& stud)
{
    cout << "CStudent::CStudent(const CStudent& stud)" << endl;

#ifdef RESOURCE
    SetName(stud.m_pszname);
#else
    SetName(stud.m_szname);
#endif

    SetNo(stud.m_no);

    SetAge(stud.m_nage);
}

void 
CStudent::CopyObject(const CStudent& stud)
{
    //本质上同拷贝构造函数一样的
#ifdef RESOURCE
    SetName(stud.m_pszname);
#else
    SetName(stud.m_szname);
#endif
    
    SetNo(stud.m_no);
    
    SetAge(stud.m_nage);
}

static int
IsRepeated(int no)
{
    for (int i = 0; i < g_ncount; i++)
    {
        if (no == g_arystud[i].GetNo())
        {
            return REPEATED;
        }
    }

    return SUCCESS;
}

int
AddStudent(CStudent student)
{
    //g_arystud[g_ncount++] = student;
    int nresult = IsRepeated(student.GetNo());
    if (REPEATED == nresult)
    {
        return REPEATED;
    }

    if (MAX_STUDENT == g_ncount)
    {
        return NO_SPACE;
    }

    g_arystud[g_ncount++].CopyObject(student);  //调用一个“拷贝”函数，存储到数组中
    
    return SUCCESS;
}

void
ShowStudent(void)
{
    for (int i = 0; i < g_ncount; i++)
    {
        cout << g_arystud[i].GetName() << " "
             << g_arystud[i].GetNo() << " "
             << g_arystud[i].GetAge() 
             << endl;
    }
}
