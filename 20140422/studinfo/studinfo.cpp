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
#ifndef USE_HEAP  //全局数据区存储固定的学生信息

static const int MAX_STUDENT = 10;
static CStudent g_arystud[MAX_STUDENT];  //这里会调用默认构造函数

#else               //动态申请堆空间存储学生信息

static int MAX_STUDENT = 0;     //需用户输入改变
static CStudent *g_pstud;       

#endif

static int g_ncount = 0;    //已存储的学生数目


//全局递增学号
static int g_studno = 0;

void
CStudent::SetName(const char *pszname)
{
#ifdef RESOURCE
    //m_pszname = (char *)malloc(strlen(pszname) + 1);
    m_pszname = new char[strlen(pszname) + 1];
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

    m_no = 0;
    m_nage = 0;
#ifdef RESOURCE
    m_pszname = NULL;
#else
    memset(m_szname, 0, sizeof(m_szname));
#endif
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
    //
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
#ifndef USE_HEAP
        if (no == g_arystud[i].GetNo())
#else
        if (no == g_pstud[i].GetNo())
#endif
        {
            return REPEATED;
        }
    }

    return SUCCESS;
}

int
AddStudent(CStudent &student)
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

#ifndef USE_HEAP
    g_arystud[g_ncount++].CopyObject(student);  //调用一个“拷贝”函数，存储到数组中
#else
    g_pstud[g_ncount++].CopyObject(student);    
#endif
    
    return SUCCESS;
}

void
ShowStudent(void)
{
    for (int i = 0; i < g_ncount; i++)
    {
    #ifndef USE_HEAP
        cout << g_arystud[i].GetName() << " "
             << g_arystud[i].GetNo() << " "
             << g_arystud[i].GetAge() 
             << endl;

    #else
        cout << g_pstud[i].GetName() << " "
             << g_pstud[i].GetNo() << " "
             << g_pstud[i].GetAge()
             << endl;
    #endif
    }
}

#ifdef USE_HEAP
int 
SetStudNumber(int &nNumber)
{
    MAX_STUDENT = nNumber;

    g_pstud = new CStudent[MAX_STUDENT];
    if (NULL == g_pstud)
    {
        return NO_SPACE;
    }

    return SUCCESS;
}

int
FreeSpace(void)
{
    delete[] g_pstud;
    
    //注意规范性处理，
    g_pstud = NULL;

    return SUCCESS;
}

#endif

