#include <string.h>

#include "mystring.h"

CMyString::CMyString(const char *pstr)
{
    strcpy(m_str, pstr);
}


const char *
CMyString::GetString(void)
{
    return m_str;
}
    
char *
CMyString::StrCpy(CMyString *str)
{
    strcpy(m_str, str->m_str);
    return m_str;
}