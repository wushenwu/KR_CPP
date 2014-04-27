#include <string.h>
#include <ctype.h>

#include "CMyString.h"

CMyString::CMyString()
{
    StringInit();
}

CMyString::CMyString(const char *psz)
{
    //���Ƚ��г�ʼ��
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
#if 0   //�ⲻ��һ�ְ�ȫ�Ĵ���
    m_psz = NULL;
    m_nlen = 0;
    m_nspace = 0;
#else
    m_psz = new char[1];    //��Ȼ�����鷽ʽ���룬����ͳһ��
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

    //�������޿ռ���пռ䵫���������ɵ����
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

    //�������޿ռ������� ��Ҫ�ر�ע����ܵ�bug
    if (ntotal > m_nspace)
    {        
        char *psztmp = new char[ntotal];
        if (NULL == psztmp)
        {
            //todo
            return NULL;
        }

        //ע������, m_psz ΪNULLʱ���ܵ�����        
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

