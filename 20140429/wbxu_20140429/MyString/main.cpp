/************************************************************************/
/* 4.ʵ��MyString�г�Ա����MyString* stringcat(MyString *pString)��Ϊһ����ַ�������,
�����������MyNumString(����˼�壬����ֻ�������ִ�),
�����������Ӻ���Ҫ�üӷ�������������23,��34�Ļ�������������������57�ˣ�����2334��
���̲�ʵ�����ǵĶ�̬��                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "CMyString.h"

/*
�����ִ����졢���õĲ���
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
�� const char *StringCat(const char *psz); �Ĳ���
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
��const char *StringCat(const CMyString &str); �Ĳ���
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
�� CMyString *StringCat(CMyString *pstr); ��̬�ԵĲ���

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