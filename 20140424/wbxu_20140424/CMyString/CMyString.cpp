#include <string.h>
#include <ctype.h>

#include "CMyString.h"

CMyString::CMyString()
{
    StringInit();
}

CMyString::CMyString(const char *psz)
{
    //需先进行初始化
    StringInit();

    SetString(psz);
}

CMyString::CMyString(const CMyString &str)
{
    StringInit();

    SetString(str);
}

CMyString::~CMyString()
{
    if (m_psz)
    {
        delete[] m_psz;
    }   

    m_psz = NULL;
    m_nlen = 0;
    m_nspace = 0;
}

void 
CMyString::StringInit(void)
{
#if 0   //这不是一种安全的处理
    m_psz = NULL;
    m_nlen = 0;
    m_nspace = 0;
#else
    m_psz = new char[1];    //仍然按数组方式申请，保持统一性
    if (m_psz)
    {
        m_psz[0] = '\0';
        m_nlen = 0;
        m_nspace = 1;
    }
    else
    {
        //TODO
    }

#endif
}

void 
CMyString::SetString(const char *psz)
{
    size_t nSpaceNeed = strlen(psz) + 1;

    //已囊括无空间和有空间但不足以容纳的情况
    if (nSpaceNeed > m_nspace)  
    {
        if (m_psz)
        {
            delete[] m_psz;
        }        
        
        m_psz = new char[nSpaceNeed];
        if (NULL == m_psz)
        {
            //TODO;
            return;
        }

        m_nspace = nSpaceNeed;  
    }
   
    strcpy(m_psz, psz);
    m_nlen = nSpaceNeed - 1;
        
    return;
}

void 
CMyString::SetString(const CMyString &str)
{
    SetString(str.m_psz);
}

const char *
CMyString::StringCopy(const char *psz)
{
    SetString(psz);
    return m_psz;
}

const char *
CMyString::StringCopy(const CMyString &str)
{
    SetString(str.m_psz);
    return m_psz;
}

const char *
CMyString::StringCat(const char *psz)
{
    size_t nSpaceNeed = strlen(psz) + 1;
    size_t ntotal = m_nlen + nSpaceNeed;

    //已囊括无空间的情况， 但要特别注意可能的bug
    if (ntotal > m_nspace)
    {        
        char *psztmp = new char[ntotal];
        if (NULL == psztmp)
        {
            //todo
            return NULL;
        }

        //注意这里, m_psz 为NULL时可能的问题        
        psztmp[0] = '\0';        
        if (m_psz)
        {
            strcpy(psztmp, m_psz);  
            delete[] m_psz;
        }
        
        m_psz = psztmp;        
        m_nspace = ntotal;

    }//end for if (ntotal > m_nspace)
   
    strcat(m_psz, psz);
    m_nlen = ntotal - 1;

    return m_psz;
}

const char *
CMyString::StringCat(const CMyString &str)
{
    return StringCat(str.m_psz);
}

bool 
CMyString::StringCompare(const char *psz) const
{
    int nresult = strcmp(m_psz, psz);
    if (0 == nresult)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool 
CMyString::StringCompare(const CMyString &str) const
{
    return StringCompare(str.m_psz);
}

const char *
CMyString::StringChr(int ch) const
{
    return strchr(m_psz, ch);
}

const char *
CMyString::StringRchr(int ch) const
{
    return strrchr(m_psz, ch);
}

const char *
CMyString::StringPbrk(const char *pszgroup) const
{
    return strpbrk(m_psz, pszgroup);
}

const char *
CMyString::StringPbrk(const CMyString &str) const
{
    return strpbrk(m_psz, str.m_psz);
}

const char *
CMyString::StringStr(const char *psz) const
{
    return strstr(m_psz, psz);
}

const char *
CMyString::StringStr(const CMyString &str) const
{
    return strstr(m_psz, str.m_psz);
}

void 
CMyString::StringToUpper(void)
{
   for (size_t i = 0; i < m_nlen; i++)
   {
       m_psz[i] = toupper(m_psz[i]);
   }
}

void 
CMyString::StringToLower(void)
{
    for (size_t i = 0; i < m_nlen; i++)
    {
        m_psz[i] = tolower(m_psz[i]);
   }
}

