#ifndef STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

/************************************************************************/
/* 3.将学员录入程序中的学生和老师加入多态性，
以适应不同的学生(学生都有说话成员函数可能有的学生是聋哑生，他们的说话方法即为手语)
和老师的多态性(老师分为老教师和新教师，
    老教师都用正常教学，新教师喜欢用多媒体教学，老师有教学这个成员方法)                                                                     */
/************************************************************************/

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

    CStudent() { }     //默认无参构造

    CStudent(const char *pszname, 
            int nyear, int nmonth, int nday,
            int id)
            : m_strname(pszname),
            m_birthday(nyear, nmonth, nday),
            m_id(id)
    { }

    CStudent(const CMyString &strname, const CMyDate &date, const CStudID &id)  //有参构造
            : m_strname(strname), m_birthday(date), m_id(id)
    { }

    CStudent(const CStudent &stud)      //拷贝构造
        : m_strname(stud.m_strname),
        m_birthday(stud.m_birthday),
        m_id(stud.m_id)
    { } 


    virtual ~CStudent() { }

    virtual void Speak(void);   //虚函数


public:     //普通成员函数
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
    Function: 返回生日的字符串
    Param   : pszbirthday用于接收生日字符串, ch为分隔符 yychmmchdd
    */
    void GetBirthday(char **pszbirthday, char ch = '-') const;

    
public:
    void CopyObject(const CStudent& stud);  //拷贝到数组中

//private:   
protected:  //需要被继承出去
    CMyString m_strname;
    CMyDate m_birthday;
    CStudID m_id;

    int m_nage;
};

//////////////////////////////////////////////////////////////////////////
//接下来是学生派生
//////////////////////////////////////////////////////////////////////////
class CStudHealthy: public CStudent
{
public:
    void Speak(void);
    
};

class CStudDeaf: public CStudent
{
public:
    void Speak(void);
};

//////////////////////////////////////////////////////////////////////////
//接下来是老师相关，简易处理
//////////////////////////////////////////////////////////////////////////
class CTeacher
{
public:
    virtual void Teach(void);
};

class CTeacherOld: public CTeacher
{
public:
    void Teach(void);
};

class CTeacherNew: public CTeacher
{
public:
    void Teach(void);
};
//////////////////////////////////////////////////////////////////////////
//接下来是存储相关
//////////////////////////////////////////////////////////////////////////
#define     SUCCESS     0
#define     NO_SPACE    1
#define     REPEATED    2

/*
Function: 向学生数组中添加新学生

Return: SUCCESS 成功  NO_SPACE 数组空间已满  REPEATED 学号重复
*/
int
AddStudent(CStudent &student);

/*
Function: 展示所有已添加学生
*/
void
ShowStudent(void);

/*
Function: 设置需要存储的学生数目, 同时申请相应的堆空间

Return  : SUCCESS 设置、申请成功； NO_SPACE 申请空间失败
*/
int 
SetStudNumber(int &nNumber);

/*
Function: 释放堆空间，删除学生信息
*/
int
FreeSpace();

#endif