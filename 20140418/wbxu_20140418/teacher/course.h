#ifndef COURSE_H_A9ADF8D4_9A76_4545_9597_8BE9D471F26D

#define COURSE_H_A9ADF8D4_9A76_4545_9597_8BE9D471F26D

#include <string.h>

class CCourse
{
public:
    void SetCourse(char *szname) { SetName(szname); }
    void SetName(char *szname) { strncpy(m_szname, szname, 15); m_szname[15] = '\0'; }

public:
    char *GetCourse() { return GetName(); }
    char *GetName() { return m_szname; }

private:
    char m_szname[16];
};

#endif
