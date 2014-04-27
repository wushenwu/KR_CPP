#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

class CStudent;   //��ǰ����

class COther
{
public:
    COther() 
    { 
        m_pstudobject = CreateOjbect(); 
    }

    ~COther();

public: //�½�CStudent����
    CStudent *CreateOjbect(void);

private:
    CStudent *m_pstudobject;
};
 
class CStudent
{
    friend CStudent *COther::CreateOjbect(void);

public: //����static��Ա�������ڶ�������ڣ����Կ�����ȥ��������
    static CStudent *CreateObject(void);

private:    //����Ĺ�����Ϊ˽�У����޷���������. ����������Ԫ��Ա����CreateObject���д���
            //�����������������Ҳ����
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