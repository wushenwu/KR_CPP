#ifndef  STUDENT_H_4F352776_1FE2_466a_922D_E43D02ED5FD7

#define  STUDENT_H_4F352776_1FE2_466a_922D_E43D02ED5FD7

#include "course.h"

class CStudent
{
public:
    void SetCourse(int index, char *szname) { course[index - 1].SetCourse(szname); }

public:
    char *GetCourse(int index) { return course[index - 1].GetCourse(); }

private:
    //作为人的shuxing

    //const int MAX_COURSE = 5;  
    CCourse course[5];          //[MAX_COURSE]
};

#endif