#include <iostream>
using namespace std;

#include "course.h"
#include "teacher.h"
#include "student.h"

void
test_course(void)
{
    CCourse course;

    course.SetCourse("CPP");

    cout << course.GetName() << endl;
}

void
test_teacher(void)
{
    CTeacher teacher;

    teacher.SetCourse(1, "CPP", "Sunday, 10:00am");
    cout << teacher.GetCourse(1) << " " << teacher.GetTime(1) << endl;

    teacher.SetTime(1, "Monday, 10:00am");
    cout << teacher.GetCourse(1) << " " << teacher.GetTime(1) << endl;

    teacher.SetCourse(1, "C++");
    cout << teacher.GetCourse(1) << " " << teacher.GetTime(1) << endl;
    
    teacher.SetCourse(2, "C", "Monday, 3:00pm");
    cout << teacher.GetCourse(2) << " " << teacher.GetTime(2) << endl;
}

void
test_student(void)
{
    CStudent student;

    student.SetCourse(1, "CPP");
    cout << student.GetCourse(1) << endl;

    student.SetCourse(2, "C");
    cout << student.GetCourse(2) << endl;
}

int
main(void)
{
    test_course();

    test_teacher();

    test_student();

    return 0;
}