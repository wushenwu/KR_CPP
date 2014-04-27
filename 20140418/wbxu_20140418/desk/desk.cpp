#include "desk.h"


void CDesk::SetDesk(float flen, float fwidth, float fheight, COLOR enucolor) 
{
    SetLen(flen);
    SetWidth(fwidth);
    SetHeight(fheight);
    SetColor(enucolor);
}

void CDesk::SetLen(float flen) 
{ 
    m_flen = flen; 
}
void CDesk::SetWidth(float fwidth) 
{
    m_fwidth = fwidth; 
}
void CDesk::SetHeight(float fheight) 
{ 
    m_fheight = fheight; 
}

//void SetColor(char *pszcolor) { strncpy(m_szcolor, pszcolor, 15); m_szcolor[15] = '\0'; }
void CDesk::SetColor(COLOR enucolor)
{ 
    m_enucolor = enucolor;
}

float CDesk::GetLen() 
{
    return m_flen; 
}

float CDesk::GetWidth() 
{
    return m_fwidth; 
}

float CDesk::GetHeight() 
{ 
    return m_fheight; 
}

CDesk::COLOR CDesk::GetColor() 
{ 
    return m_enucolor; 
}
