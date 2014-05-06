/************************************************************************/
/* 3.��ѧԱ¼������е�ѧ������ʦ�����̬�ԣ�
����Ӧ��ͬ��ѧ��(ѧ������˵����Ա���������е�ѧ���������������ǵ�˵��������Ϊ����)
����ʦ�Ķ�̬��(��ʦ��Ϊ�Ͻ�ʦ���½�ʦ��
    �Ͻ�ʦ����������ѧ���½�ʦϲ���ö�ý���ѧ����ʦ�н�ѧ�����Ա����)                                                                     */
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
