#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

//#define STATIC  //ʹ��static���ݳ�Ա�������ü���

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
    
    //�����ü������
    void AddRef(void);
    void Release(void);

private:
    char *m_pszname;
    int m_no;

#ifdef STATIC
    static int m_nrefcount;     //ʹ�þ�̬���ݳ�Ա�������ü���
#else
    int *m_prefcount;    //���ü�����������Ϊһ����Դ�����в�ͬ��Դ������ĸ���
                                //����ԴΪ���ĵ����ü���
#endif
};


#endif