#ifndef PERSON_H_A915AA7E_B87F_464c_BAC1_2708CC4BCACE

#define PERSON_H_A915AA7E_B87F_464c_BAC1_2708CC4BCACE

class CPerson
{
public:
    void SetPerson(char *szname, char *szaddress, int nage, char chgender);
    void SetName(char *szname);
    void SetAddress(char *szaddress);
    void SetAge(int nage);
    void SetGender(char chgender);

public:
    char *GetName();
    char *GetAddress();
    int GetAge();
    char GetGender();

private:
    char m_szname[64];
    char m_szaddress[128];
    int m_nage;
    char m_chgender;
};

#endif
