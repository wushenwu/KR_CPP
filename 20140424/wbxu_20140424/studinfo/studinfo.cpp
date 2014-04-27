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

/*存储相关  动态申请堆空间存储学生信息 */

static int MAX_STUDENT = 0;     //需用户输入改变
static CStudent *g_pstud;      
static int g_ncount = 0;        //已存储的学生数目

void
CStudent::SetName(const char *pszname)
{
    m_strname.SetString(pszname);
}

void 
CStudent::SetName(const CMyString &strname)
{
    m_strname.SetString(strname);
}

void
CStudent::SetNo(int no)
{
    m_id.SetNo(no);
}

void 
CStudent::SetNo(const CStudID &id)
{
    m_id.SetNo(id.GetNo());
}


void 
CStudent::SetBirthday(int nyear, int nmonth, int nday)
{
    m_birthday.SetDate(nyear, nmonth, nday);
}

void 
CStudent::SetBirthday(const CMyDate &date)
{
    m_birthday.SetDate(date);
}

void
CStudent::SetAge(int nage)
{
    m_nage = nage;
}

const char *
CStudent::GetName(void) const
{
    return m_strname.GetString();
}

int
CStudent::GetNo(void) const
{
    return m_id.GetNo();
}

CMyDate 
CStudent::GetBirthday(void) const
{
    return m_birthday;
}

void 
CStudent::GetBirthday(char **pszbirthday, char ch) const
{
    m_birthday.GetDate(pszbirthday, ch);
}

int
CStudent::GetAge(void) const
{
    return m_nage;
}

void 
CStudent::CopyObject(const CStudent& stud)
{
    SetName(stud.m_strname);
    SetBirthday(stud.m_birthday);
    SetNo(stud.m_id);
}

//////////////////////////////////////////////////////////////////////////
////存储相关
////

static int
IsRepeated(int no)
{
    for (int i = 0; i < g_ncount; i++)
    {
        if (no == g_pstud[i].GetNo())
        {
            return REPEATED;
        }
    }

    return SUCCESS;
}

int
AddStudent(CStudent &student)
{
    int nresult = IsRepeated(student.GetNo());
    if (REPEATED == nresult)
    {
        return REPEATED;
    }

    if (MAX_STUDENT == g_ncount)
    {
        return NO_SPACE;
    }

    g_pstud[g_ncount++].CopyObject(student);    
    
    return SUCCESS;
}

void
ShowStudent(void)
{
    char szbirthday[64] = {0};
    char *pszbirthday = szbirthday;
    for (int i = 0; i < g_ncount; i++)
    {
        g_pstud[i].GetBirthday(&pszbirthday);
        
        cout << g_pstud[i].GetName() << " "
             << g_pstud[i].GetNo() << " "
             << szbirthday
             << endl;
    }
}

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
    if (g_pstud)
    {
        delete[] g_pstud;
    }
    g_pstud = NULL;    

    return SUCCESS;
}