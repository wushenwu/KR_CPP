#include <stdio.h>
#include "CMyDate.h"

CMyDate::CMyDate()
{
    init(-1, 0, 0);
}

CMyDate::CMyDate(int nyear, int nmonth, int nday)
{
    init(nyear, nmonth, nday);
}

CMyDate::CMyDate(const CMyDate &date)
{
    init(date.m_nyear, date.m_nmonth, date.m_nday);
}

CMyDate::~CMyDate()
{
    init(-1, 0, 0);
}
    
bool
CMyDate::init(int nyear, int nmonth, int nday)
{
    m_nyear  = nyear;
    m_nmonth = nmonth;
    m_nday   = nday;

    if (false == isvalidyear(nyear)
        || false == isvalidmonth(nmonth)
        || false == isvalidday(nyear, nmonth, nday))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool
CMyDate::SetDate(const CMyDate &date)
{
    return init(date.m_nyear, date.m_nmonth, date.m_nday);
}

bool 
CMyDate::SetDate(int nyear, int nmonth, int nday)
{
    return init(nyear, nmonth, nday);
}

bool 
CMyDate::SetYear(int nyear)
{
    m_nyear = nyear;
    
    return isvalidyear(nyear);
}

bool 
CMyDate::SetMonth(int nmonth)
{
    m_nmonth = nmonth;

    return isvalidmonth(nmonth);
}
    
bool 
CMyDate::SetDay(int nday)
{
    m_nday = nday;

    return isvalidday(m_nyear, m_nmonth, nday);
}

int 
CMyDate::GetYear(void) const
{
    return m_nyear;
}

int 
CMyDate::GetMonth(void) const
{
    return m_nmonth;
}

int 
CMyDate::GetDay(void) const
{
    return m_nday;
}

void 
CMyDate::GetDate(char **pszdate, char ch) const
{
     sprintf(*pszdate, "%4d%c%02d%c%02d",
         m_nyear, ch, m_nmonth, ch, m_nday);
}

bool 
CMyDate::isleapyear(int nyear) const
{
    //四年一闰，百年不闰，四百年再闰
    if ((0 == nyear % 4 && 0 != nyear % 100)
        || (0 == nyear % 400)
        )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
CMyDate::isvalidyear(int nyear) const
{
    if (nyear <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool 
CMyDate::isvalidmonth(int nmonth) const
{
    if (nmonth < 1
    || nmonth > 12)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool
CMyDate::isvalidday(int nyear, int nmonth, int nday) const
{
    if (nday < 1
        || nday > 31)
    {
        return false;
    }

    if (isleapyear(nyear) && 2 == nmonth && nday != 29
        || !isleapyear(nyear) && 2 == nmonth && nday != 28)
    {
        return false;
    }

    if (nmonth < 8 
        && ((nmonth & 1) != 0) // 1, 3, 5, 7
        && m_nday != 31
        )
    {   
        return false;
    }

    if (nmonth >= 8 
        && (0 == (nmonth & 1)) // 8, 10, 12
        && m_nday != 31
        )
    {   
        return false;
    }

    if ((4 == nmonth || 6 == nmonth || 9 == nmonth || 11 == nmonth)
        && m_nday != 30)
    {
        return false;
    }

    return true;
}