/************************************************************************/
/* 2.дһ���ַ�����MyString�������е�strcpy(MyString *)��Ա����ʵ��C���Կ⺯����strcpy��
  ������������⣬�ַ���������200���ַ�����                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "mystring.h"

int
main(void)
{
    CMyString str("Hello world");

    cout << str.GetString() << endl;

    CMyString tmp = "Copyingggggggggggggggg";
    cout << str.StrCpy(&tmp) << endl;
    return 0;
}