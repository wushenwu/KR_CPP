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

/*�洢���*/
#ifndef USE_HEAP  //ȫ���������洢�̶���ѧ����Ϣ

static const int MAX_STUDENT = 10;
static CStudent g_arystud[MAX_STUDENT];  //��������Ĭ�Ϲ��캯��

#else               //��̬����ѿռ�洢ѧ����Ϣ

static int MAX_STUDENT = 0;     //���û�����ı�
static CStudent *g_pstud;       

#endif

static int g_ncount = 0;    //�Ѵ洢��ѧ����Ŀ


//ȫ�ֵ���ѧ��
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
    //�ڱ����У���������洢���ʲ��ܽ�����Դ�ͷ�
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
    //������ͬ�������캯��һ����
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
    g_arystud[g_ncount++].CopyObject(student);  //����һ�����������������洢��������
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
    
    //ע��淶�Դ���
    g_pstud = NULL;

    return SUCCESS;
}

#endif

