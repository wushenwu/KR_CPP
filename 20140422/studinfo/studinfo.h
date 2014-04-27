#ifndef STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define STUDINFO_H_4E23F273_5752_404a_8E86_B5143CC06EFB

#define RESOURCE    //���ڿ��������Ĺ���

#define USE_HEAP    //�öѿռ�洢����ѧ����Ϣ

class CStudent
{
public:     //���캯��
    CStudent();                             //Ĭ�Ϲ��캯��
    CStudent(const char *pszname, int nage = 20);  //����Ĭ��, ѧ�ŵ���
    CStudent(int no, const char *pszname);         //

public:
    ~CStudent();

public:     //�������캯��
    CStudent(const CStudent& stud);

public:     //��ͨ��Ա����
    void SetName(const char *pszname);
    void SetNo(int no);
    void SetAge(int nage);

    const char *GetName(void);
    int GetNo(void);
    int GetAge(void);

public:
    void CopyObject(const CStudent& stud);  //������������

private:
#ifdef RESOURCE
    char *m_pszname;
#else
    char m_szname[64];
#endif
    int m_no;          //ѧ��    
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