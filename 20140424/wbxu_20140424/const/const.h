#ifndef TEST_H_83842F04_AFE3_4d0a_A20D_E4975B8EE899

#define TEST_H_83842F04_AFE3_4d0a_A20D_E4975B8EE899

#define CONST

class CConst
{
public:
    CConst();
    CConst(int n1, char *psz);
    CConst(const CConst &object);

    ~CConst();

    void SetNum1(int n1);
    void SetName(const char *pszname);
    
    int GetNum1(void) const;

#ifndef CONST

    char *GetName(void) const;

#else
    const char *GetName(void) const;

#endif

private:
    void init(int n1, char *psz);

public:
    int m_n2;

private:
    int m_n1;
    char *m_psz;
};

#endif
