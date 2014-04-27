#ifndef TEACHER_H_E615C6F2_B437_478e_9265_181D8C91481B

#define TEACHER_H_E615C6F2_B437_478e_9265_181D8C91481B

#include "course.h"

class CTeacher
{
public:
    void SetCourse(int index, char *szname, char *sztime) { SetCourse(index, szname); SetTime(index, sztime); }
    void SetCourse(int index, char *szname) { m_course[index - 1].SetCourse(szname); }
    void SetTime(int index, char *sztime) 
    {
        strncpy(m_sztime[index - 1], sztime, 31); 
        m_sztime[index - 1][31] = '\0';
    }

public:
    char *GetCourse(int index) { return m_course[index - 1].GetCourse(); }
    char *GetTime(int index) { return m_sztime[index - 1]; } 

private:
    //作为人的基本属性
    //char m_szname[64];
    //char m_szaddress[128];
    //int m_nage;
    //char m_chgender;

    //const int MAX_COURSE = 2; 这样不可以

    CCourse m_course[2]; //[MAX_COURSE];
    char m_sztime[2][32];    //[MAX_COURSE][32];
};

#endif