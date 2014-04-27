#include <string.h>
#include "person.h"


void CPerson::SetPerson(char *szname, char *szaddress, int nage, char chgender)
{
    SetName(szname);
    SetAddress(szaddress);
    SetAge(nage);
    SetGender(chgender);
}

void CPerson::SetName(char *szname)
{
    strncpy(m_szname, szname, 63);
    m_szname[63] = '\0';
}

void CPerson::SetAddress(char *szaddress)
{
    strncpy(m_szaddress, szaddress, 127);
    m_szaddress[127] = '\0';
}

void CPerson::SetAge(int nage)
{
    m_nage = nage;
}

void CPerson::SetGender(char chgender)
{
    m_chgender = chgender;
}

char *CPerson::GetName()
{
    return m_szname;
}
    
char *CPerson::GetAddress()
{
    return m_szaddress;
}

int CPerson::GetAge()
{
    return m_nage;
}
 
char CPerson::GetGender()
{
    return m_chgender;
}