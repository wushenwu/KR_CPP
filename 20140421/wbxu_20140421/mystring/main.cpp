/************************************************************************/
/* 2.写一个字符串类MyString，以其中的strcpy(MyString *)成员方法实现C语言库函数的strcpy，
  不考虑溢出问题，字符串长度在200个字符以内                                                                     */
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