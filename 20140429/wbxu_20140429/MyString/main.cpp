/************************************************************************/
/* 4.实现MyString有成员函数MyString* stringcat(MyString *pString)即为一般的字符串连接,
类和它的子类MyNumString(顾名思义，里面只能是数字串),
其中它的连接函数要用加法加起来，比如23,和34的话，它们连接起来就是57了，不是2334。
请编程并实现它们的多态性                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "CMyString.h"

/*
对数字串构造、设置的测试
*/
void
test_num(void)
{
    CMyNumString str1;
    str1.SetString("123456");

    str1.SetString("123abcde123");
    
    str1.SetString("1111111111");

    CMyNumString str2("222222222");
}

/*
对 const char *StringCat(const char *psz); 的测试
*/
void
test_cat_1(CMyString *pstrobj)
{
    pstrobj->StringCat("34");
    cout << pstrobj->GetString() << endl;

    pstrobj->StringCat("341111111111111111");
    cout << pstrobj->GetString() << endl;
}

void
test_poly_1(void)
{
    CMyString *pstrobj = NULL;
    pstrobj = new CMyString("23");
    test_cat_1(pstrobj);

    pstrobj->SetString("2311111111111111111111");
    test_cat_1(pstrobj);

    pstrobj = new CMyNumString("23");
    test_cat_1(pstrobj);

    pstrobj->SetString("2311111111111111111111");
    test_cat_1(pstrobj);

    if (pstrobj != NULL)
    {
        delete pstrobj;
        pstrobj = NULL;
    }
}

/*
对const char *StringCat(const CMyString &str); 的测试
*/
void
test_cat_2(CMyString *pstrobj)
{
    CMyString strtmp("1234");

    pstrobj->StringCat(strtmp);
    cout << pstrobj->GetString() << endl;
}

void
test_poly_2(void)
{
    CMyString *pstrobj = NULL;
    pstrobj = new CMyString("1234");
    test_cat_2(pstrobj);

    pstrobj = new CMyNumString("1234");
    test_cat_2(pstrobj);

    if (pstrobj != NULL)
    {
        delete pstrobj;
        pstrobj = NULL;
    }
}

/*
对 CMyString *StringCat(CMyString *pstr); 多态性的测试

*/
void test_cat_3(CMyString *pstrobj)
{
    if (pstrobj != NULL)
    {
        CMyString *pstrtmp = new CMyString("1234");
        cout << pstrobj->StringCat(pstrtmp)->GetString() << endl;
    }
}

void
test_poly_3(void)
{
    CMyString *pstrobj = NULL;

    pstrobj = new CMyString("1234");
    test_cat_3(pstrobj);

    pstrobj = new CMyNumString("1234");
    test_cat_3(pstrobj);

    if (pstrobj != NULL)
    {
        delete pstrobj;
        pstrobj = NULL;
    }    
}

int
main(void)
{
    test_num();

    test_poly_1();

    test_poly_2();

    test_poly_3();

    return 0;
}