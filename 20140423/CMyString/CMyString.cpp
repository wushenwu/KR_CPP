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
    delete[] m_psz;
    m_psz = NULL;

    m_nlen = 0;
    m_nspace = 0;
}

void 
CMyString::StringInit(void)
{
    m_psz = NULL;
    m_nlen = 0;
    m_nspace = 0;
}

void 
CMyString::SetString(const char *psz)
{
#if 0
    size_t nSpaceNeed = strlen(psz) + 1;

    //case 1: û�пռ䡪���޲ι�������
    //      ���Ȼ��nSpaceNeed > m_nSpace, ���Կ��Ժϲ�
    if (NULL == m_psz)
    {
        m_psz = new char[nSpaceNeed];
        if (m_psz)
        {
            strcpy(m_psz, psz);
            m_nlen = nSpaceNeed - 1;
            m_nspace = nSpaceNeed;
        }
        else
        {
            TODO;
        }
        return;
    }//end for if (NULL == m_psz)

    //case 2: ���㹻�ռ�����
    if (nSpaceNeed <= m_nspace)
    {
        strcpy(m_psz, psz);
        m_nlen = nSpaceNeed - 1;

        return;
    }

    //case 3: �пռ䣬������������
    if (nSpaceNeed > m_nspace)
    {
        delete[] m_psz;
        
        m_psz = new char[nSpaceNeed];
        if (m_psz)
        {
            strcpy(m_psz, psz);
            m_nlen = nSpaceNeed - 1;
            m_nspace = nSpaceNeed;  
        }
        else
        {
            //TODO;
        }
        return;
    }//end for if (nSpaceNeed > m_nspace)

#else

    size_t nSpaceNeed = strlen(psz) + 1;

    //�������޿ռ���пռ䵫���������ɵ����
    if (nSpaceNeed > m_nspace)  
    {
        delete[] m_psz;     //delete null ok ??
        
        m_psz = new char[nSpaceNeed];
        if (m_psz)
        {
            strcpy(m_psz, psz);
            m_nlen = nSpaceNeed - 1;
            m_nspace = nSpaceNeed;  
        }
        else
        {
            //TODO;
        }
        return;
    }//end for if (nSpaceNeed > m_nspace)
    else
    {
        strcpy(m_psz, psz);
        m_nlen = nSpaceNeed - 1;
        
        return;
    }

#endif
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
#if 0
    size_t nSpaceNeed = strlen(psz) + 1;

    //case 1: �޿ռ�
    // ��Ȼ������nSpaceNeed > m_nspace �У����Խ����Ż�
    if (NULL == m_psz)
    {
        m_psz = new char[nSpaceNeed];
        if (m_psz)
        {
            strcpy(m_psz, psz);
            m_nlen = nSpaceNeed - 1;
            m_nspace = nSpaceNeed;
        }
        else
        {
            //todo
        }

        return m_psz;
    }

    //case 2: �ռ����
    if (nSpaceNeed <= m_nspace)
    {
        strcat(m_psz, psz);
        m_nlen += (nSpaceNeed - 1);
        m_nspace += nSpaceNeed;

        return m_psz;
    }

    //case 3: �пռ䣬���ռ䲻��������
    if (nSpaceNeed > m_nspace)
    {
        int ntotal = m_nspace + nSpaceNeed;
        char *psztmp = new char[ntotal];
        if (psztmp)
        {
            strcpy(psztmp, m_psz);
            delete[] m_psz;
            m_psz = psztmp;

            strcat(m_psz, psz);
            m_nlen = ntotal - 1;
            m_nspace = ntotal;
        }
        else
        {
            //todo
        }
        
        return m_psz;

    }//end for if (nSpaceNeed > m_nspace)

#else

    size_t nSpaceNeed = strlen(psz) + 1;

    //�������޿ռ������� ��Ҫ�ر�ע����ܵ�bug
    if (nSpaceNeed + m_nlen > m_nspace)
    {
        int ntotal = m_nlen + nSpaceNeed;
        char *psztmp = new char[ntotal];
        if (psztmp)
        {
            //ע������, m_psz ΪNULLʱ���ܵ�����

            psztmp[0] = '\0';
           
            if (m_psz)
            {
                strcpy(psztmp, m_psz);  
            }
            
            delete[] m_psz;
            m_psz = psztmp;
            
            strcat(m_psz, psz);
            m_nlen = ntotal - 1;
            m_nspace = ntotal;
        }
        else
        {
            //todo
        }

        return m_psz;

    }//end for if (nSpaceNeed + m_nlen > m_nspace)
    else
    {
        strcat(m_psz, psz);
        m_nlen += (nSpaceNeed - 1);
        m_nspace += nSpaceNeed;
        
        return m_psz;
    }

#endif
}

const char *
CMyString::StringCat(const CMyString &str)
{
    return StringCat(str.m_psz);
}

bool 
CMyString::StringCompare(const char *psz)
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
CMyString::StringCompare(const CMyString &str)
{
    return StringCompare(str.m_psz);
}

char *
CMyString::StringChr(int ch)
{
    return strchr(m_psz, ch);
}

char *
CMyString::StringRchr(int ch)
{
    return strrchr(m_psz, ch);
}

char *
CMyString::StringPbrk(const char *pszgroup)
{
    return strpbrk(m_psz, pszgroup);
}

char *
CMyString::StringPbrk(const CMyString &str)
{
    return strpbrk(m_psz, str.m_psz);
}

char *
CMyString::StringStr(const char *psz)
{
    return strstr(m_psz, psz);
}

char *
CMyString::StringStr(const CMyString &str)
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

