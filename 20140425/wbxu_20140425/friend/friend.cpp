#include <iostream>
using namespace std;

#include "friend.h"

/*
�ó�Ա�����ѱ�����ΪCStudent����Ԫ���������ԣ����Է�����˽�г�Ա
*/
void
COther::func(void)
{
    CStudent stud;
    stud.m_no = 0x1234;

    stud.init(0x5678);

    //��Ȼ�ˣ�����Ч�������ǣ�func(CStudent &object)����func�ж�object�����޸�
    //�����ǵ����Ǽ���໥������Ŀǰ�޷����
}

/*
 ��CStudent�Ĺ��챻����Ϊ˽�У�����;���޷��������������£�
    ͨ������Ԫ��Ա���������Դ���CStudent����
    ���ﺯ����ʵ�֣�ʹ�ö�����ܲ����ڶ��ϡ�
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
