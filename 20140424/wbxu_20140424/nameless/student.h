#ifndef STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

#define STUDENT_H_CF623E79_389B_4e2a_A81E_D661C9C74C6E

class CStudent
{
public:
    CStudent();
    CStudent(int no, char *pszname = "student");

    CStudent(const CStudent &stud);

public:
    ~CStudent();

public:
    void SetName(const char *pszname);
    void SetNo(int no);

    const char *GetName(void);
    int GetNo(void);

private:
    char *m_pszname;
    int m_no;
};

#endif