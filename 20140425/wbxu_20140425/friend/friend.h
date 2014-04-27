#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

class CStudent;     //��ǰ����

class COther        
{
public:
    void func(void);
    CStudent *CreateObject(void);
};
 
class CStudent
{
    //����ͨ��������Ϊ�������Ԫ
    friend void normal_func(void);

    //�������Ա��������Ϊ�������Ԫ
    friend void COther::func(void);
    friend CStudent * COther::CreateObject(void);

    //����������Ϊ�������Ԫ, ���ڸ����Ƿ���ڣ��Ƿ�ʵ�֣��������м��
    friend class C;
    
private:    //����Ĺ�����Ϊ˽�У����޷���������. ����������Ԫ��Ա����CreateObject���д���
    CStudent();
    CStudent(int no, char *pszname = "student");

    CStudent(const CStudent &stud);

public:
    ~CStudent();

    void KillMe(void);

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