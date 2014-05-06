/************************************************************************/
/* 5.дһ��person�����������ԣ������������ڶ�������ġ�
����һ�����������࣬����������������⻹��һ������,Ҳ���ڶ�������ġ�
����sayName��������ʵ����������Ķ�̬�ԡ�(��ʾ��ע����������)                                                                     */
/************************************************************************/

#ifndef WRITER_H_67D37360_C4B9_45b6_9C83_F6A512965472

#define WRITER_H_67D37360_C4B9_45b6_9C83_F6A512965472

#include "CMyString.h"

//#define USE_MYSTRING

#ifndef USE_MYSTRING

class CPerson
{
public:
    CPerson();
    CPerson(const char *pszname);
    CPerson(const CPerson &obj);

    virtual ~CPerson();

    void SetName(const char *pszname);

    virtual void SayName(void) const; 
    
protected:
    void Init(char **pdst);
    void SetData(char **pdst, const char *psrc);
    void Release(char **pdst);

protected:
    char *m_pstrname;
};

class CWriter: public CPerson
{
public:
    CWriter();
    CWriter(const char *pszname, const char *pszsign = NULL);
    CWriter(const CWriter &obj);

    ~CWriter();

    void SetName(const char *pszname, const char *pszsign);

    void SayName(void) const;

private:
    char *m_pstrsign;
};


#else

class CPerson
{
public:
    CPerson() {}

    CPerson(const char *pszname)
        :m_pstrname(pszname)
    {

    }

    CPerson(const CPerson &obj)
        :m_pstrname(obj)
    {

    }

    //��Ϊʹ��CMyString�࣬���Ա����в��漰��Դ�Ĺ����ʲ�û��������������


    virtual void SayName(void) const;

protected:
    CMyString *m_pstrname;
};

class CWriter: public CPerson
{
public:
    CWriter() {};

    CWriter(const char *pszname, const char *pszsign = NULL)
        :m_pstrname(pszname),
        m_pstrsign(pszsign)
    {

    }

    //��ʹ��CMyString�࣬���漰��Դ�Ĺ�������û��������������

    virtual void SayName(void) const;

private:
    CMyString *m_pstrsign;

};

#endif

#endif
