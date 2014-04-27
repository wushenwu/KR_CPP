#ifndef STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#include "CMyString.h"
#include "CMyDate.h"

class CStudID
{
public:
    CStudID() { m_no = 0;}
    CStudID(int no) { m_no = no; }
    CStudID(const CStudID &object) { m_no = object.m_no; }

    ~CStudID() { m_no = 0; }

public:
    void SetNo(int no) { m_no = no; }
    
    int GetNo(void) const { return m_no; }
    
private:
    int m_no;
};

class CStudent
{
public:     

    CStudent() { }     //Ĭ���޲ι���

    CStudent(const char *pszname, 
            int nyear, int nmonth, int nday,
            int id)
            : m_strname(pszname),
            m_birthday(nyear, nmonth, nday),
            m_id(id)
    { }

    CStudent(const CMyString &strname, const CMyDate &date, const CStudID &id)  //�вι���
            : m_strname(strname), m_birthday(date), m_id(id)
    { }

    CStudent(const CStudent &stud)      //��������
        : m_strname(stud.m_strname),
        m_birthday(stud.m_birthday),
        m_id(stud.m_id)
    { } 


    ~CStudent() { }


public:     //��ͨ��Ա����
    void SetName(const char *pszname);
    void SetName(const CMyString &strname);

    void SetNo(int no);
    void SetNo(const CStudID &id);

    void SetBirthday(int nyear, int nmonth, int nday);
    void SetBirthday(const CMyDate &date);

    void SetAge(int nage);
    int GetAge(void) const;

    const char *GetName(void) const;
    int GetNo(void) const;
    CMyDate GetBirthday(void) const;

    /*
    Function: �������յ��ַ���
    Param   : pszbirthday���ڽ��������ַ���, chΪ�ָ��� yychmmchdd
    */
    void GetBirthday(char **pszbirthday, char ch = '-') const;

    
public:
    void CopyObject(const CStudent& stud);  //������������

private:   
    CMyString m_strname;
    CMyDate m_birthday;
    CStudID m_id;

    int m_nage;
};

//////////////////////////////////////////////////////////////////////////
//�������Ǵ洢���
//////////////////////////////////////////////////////////////////////////
#define     SUCCESS     0
#define     NO_SPACE    1
#define     REPEATED    2

/*
Function: ��ѧ�������������ѧ��

Return: SUCCESS �ɹ�  NO_SPACE ����ռ�����  REPEATED ѧ���ظ�
*/
int
AddStudent(CStudent &student);

/*
Function: չʾ���������ѧ��
*/
void
ShowStudent(void);

/*
Function: ������Ҫ�洢��ѧ����Ŀ, ͬʱ������Ӧ�Ķѿռ�

Return  : SUCCESS ���á�����ɹ��� NO_SPACE ����ռ�ʧ��
*/
int 
SetStudNumber(int &nNumber);

/*
Function: �ͷŶѿռ䣬ɾ��ѧ����Ϣ
*/
int
FreeSpace();

#endif