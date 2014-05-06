/************************************************************************/
/* 5.写一个person类有名字属性，其中名字是在堆里申请的。
其有一子类是作家类，作家类里除了名字外还有一个笔名,也是在堆里申请的。
都有sayName方法。请实现这两个类的多态性。(提示：注意析构函数)                                                                     */
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

    //因为使用CMyString类，所以本类中不涉及资源的管理，故不没处理析构函数。


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

    //因使用CMyString类，不涉及资源的管理，所以没有设置析构函数

    virtual void SayName(void) const;

private:
    CMyString *m_pstrsign;

};

#endif

#endif
