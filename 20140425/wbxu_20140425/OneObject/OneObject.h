#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

class CStudent;   //向前声明

class COther
{
public:
    COther() 
    { 
        m_pstudobject = CreateOjbect(); 
    }

    ~COther();

public: //新建CStudent对象
    CStudent *CreateOjbect(void);

private:
    CStudent *m_pstudobject;
};
 
class CStudent
{
    friend CStudent *COther::CreateOjbect(void);

public: //利用static成员函数先于对象而存在，所以可用其去创建对象
    static CStudent *CreateObject(void);

private:    //将类的构造设为私有，则无法创建对象. 但可利用友元成员函数CreateObject进行创建
            //但这里仅利用类自身也可以
    CStudent();
    CStudent(int no, char *pszname = "student");

    CStudent(const CStudent &stud);

public:
    ~CStudent();

    //void KillMe(void);

public:
    void SetName(const char *pszname);
    void SetNo(int no);

    const char *GetName(void) const;
    int GetNo(void) const;

private:
    void init(int no);

private:
    char *m_pszname;
    int m_no;
};


#endif