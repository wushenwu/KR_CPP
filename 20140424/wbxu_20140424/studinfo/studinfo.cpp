/************************************************************************/
/* 1.дһ��ѧԱ��Ϣ¼�������ѧԱ��Ϣ������������¼���ѧԱ��Ϣ�����ṩ����¼�뷽ʽ��
(1)ѧ�ź�����ΪĬ�ϣ�ѧ��Ĭ��Ϊ��1��ʼ����������Ĭ��Ϊ20
(2)ѧ�ţ��������������ΪĬ��,��ѧ�ź���������Ϊ���캯���Ĳ���(��Ҫ�ж�ѧ����Ψһ��,������������Լ�������������)
ʵ��ѧԱ��Ϣ��Ŀ�����(���ÿ������캯��)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include <string.h>
#include "studinfo.h"

/*�洢���  ��̬����ѿռ�洢ѧ����Ϣ */

static int MAX_STUDENT = 0;     //���û�����ı�
static CStudent *g_pstud;      
static int g_ncount = 0;        //�Ѵ洢��ѧ����Ŀ

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
////�洢���
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