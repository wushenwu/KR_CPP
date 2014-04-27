#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

//#define STATIC  //使用static数据成员进行引用计数

class CStudent
{
public:    
    CStudent(); 
    CStudent(int no, char *pszname);

    CStudent(const CStudent &stud);

public:
    ~CStudent();

public:
    void SetName(const char *pszname);
    void SetNo(int no);

    const char *GetName(void) const;
    int GetNo(void) const;

private:
    void init(int no);
    
    //与引用计数相关
    void AddRef(void);
    void Release(void);

private:
    char *m_pszname;
    int m_no;

#ifdef STATIC
    static int m_nrefcount;     //使用静态数据成员进行引用计数
#else
    int *m_prefcount;    //引用计数器自身作为一种资源，进行不同资源间计数的隔离
                                //以资源为中心的引用计数
#endif
};


#endif