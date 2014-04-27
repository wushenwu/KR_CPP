#ifndef MYSTRING_H_53D011ED_2552_432e_B133_426CE2B78217

#define MYSTRING_H_53D011ED_2552_432e_B133_426CE2B78217

class CMyString
{
public:
    CMyString(const char *pstr);            //¹¹Ôìº¯Êý

public:
    const char *GetString(void);

    char *StrCpy(CMyString *);

private:
    char m_str[200];
};

#endif