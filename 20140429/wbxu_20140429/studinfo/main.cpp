/************************************************************************/
/* 3.将学员录入程序中的学生和老师加入多态性，
以适应不同的学生(学生都有说话成员函数可能有的学生是聋哑生，他们的说话方法即为手语)
和老师的多态性(老师分为老教师和新教师，
    老教师都用正常教学，新教师喜欢用多媒体教学，老师有教学这个成员方法)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "studinfo.h"

void Speak(CStudent *pstudobj)
{
    if (pstudobj != NULL)
    {
        pstudobj->Speak();
    }
}

void
test_poly_stud(void)
{
    CStudent *pstudobj = NULL;
    
    //pstudobj = new CStudent;
    //pstudobj = new CStudHealthy;
    pstudobj = new CStudDeaf;
    Speak(pstudobj); 

    if (pstudobj != NULL)
    {
        delete pstudobj;
    }
}

void Teach(CTeacher *pteacherobj)
{
    if (pteacherobj != NULL)
    {
        pteacherobj->Teach();
    }
}

void
test_poly_teacher(void)
{
    CTeacher *pteacherobj = NULL;
    
    //pteacherobj = new CTeacher;
    pteacherobj = new CTeacherOld;
    //pteacherobj = new CTeacherNew;
    Teach(pteacherobj); 
    
    if (pteacherobj != NULL)
    {
        delete pteacherobj;
    }
}

int
main(void)
{
    test_poly_stud();

    test_poly_teacher();

    return 0;
}
