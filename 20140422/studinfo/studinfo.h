#ifndef STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define RESOURCE    //用于控制姓名的管理

#define USE_HEAP    //用堆空间存储所有学生信息

class CStudent
{
public:     //构造函数
    CStudent();                             //默认构造函数
    CStudent(const char *pszname, int nage = 20);  //年龄默认, 学号递增
    CStudent(int no, const char *pszname);         //

public:
    ~CStudent();

public:     //拷贝构造函数
    CStudent(const CStudent& stud);

public:     //普通成员函数
    void SetName(const char *pszname);
    void SetNo(int no);
    void SetAge(int nage);

    const char *GetName(void);
    int GetNo(void);
    int GetAge(void);

public:
    void CopyObject(const CStudent& stud);  //拷贝到数组中

private:
#ifdef RESOURCE
    char *m_pszname;
#else
    char m_szname[64];
#endif
    int m_no;          //学号    
    int m_nage;
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