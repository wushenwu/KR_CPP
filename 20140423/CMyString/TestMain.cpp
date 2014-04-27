#include <iostream>
using namespace std;

#include "CMyString.h"

void
test_construct(void)
{
    CMyString str1;

    CMyString str2("Hello world");

    CMyString str3 = str2;
}

void
test_copy(void)
{
    CMyString str1;

    str1.StringCopy("hello");
    cout << str1.GetLen() << " " << str1.GetString() << endl;

    str1.StringCopy("he");
    cout << str1.GetLen() << " " << str1.GetString() << endl;

    str1.StringCopy("hello world");
    cout << str1.GetLen() << " " << str1.GetString() << endl;
}

void
test_cat(void)
{
    CMyString str1;
    str1.StringCat("he");
    cout << str1.GetLen() << " " << str1.GetString() << endl;
    
    str1.StringCopy("hello");
    cout << str1.GetLen() << " " << str1.GetString() << endl;

    str1.StringCat(" world");
    cout << str1.GetLen() << " " << str1.GetString() << endl;
}

void
test_compare(void)
{
    CMyString str1 = "hello";
    CMyString str2(str1);

    if (str2.StringCompare("hello"))
    {
        cout << "equal";
    }

    if (str2.StringCompare(str1))
    {
        cout << "equal";
    }

    if (str2.StringCompare("helloworld"))
    {
        cout << "equal";
    }
}

void
test_chr(void)
{
    CMyString str1 = "hello";

    char *psz = str1.StringChr('l');
    if (psz)
    {
        cout << psz << endl;
    }

    psz = str1.StringRchr('l');
    if (psz)
    {
        cout << psz << endl;
    }

    psz = str1.StringChr('w');
    if (psz)
    {
        cout << psz << endl;
    }
    
}

void
test_pbrk(void)
{
    CMyString str1 = "Hi there";
    char *pgroup1 = "tr";
    char *pgroup2 = "lo3";
    CMyString strgroup1 = "lo3";
    CMyString strgroup2 = "tr";

    char *presult = str1.StringPbrk(strgroup1);
    if (presult)
    {
        cout << presult << endl;
    }

    presult = str1.StringPbrk(strgroup2);
    if (presult)
    {
        cout << presult << endl;
    }

    presult = str1.StringPbrk(pgroup1);
    if (presult)
    {
        cout << presult << endl;
    }

    presult = str1.StringPbrk(pgroup2);
    if (presult)
    {
        cout << presult << endl;
    }
}

void
test_strstr()
{
    CMyString str1 = "hello world";
    CMyString str2 = "world";

    char *pszresult = str1.StringStr("world");
    if (pszresult)
    {
        cout << pszresult << endl;
    }

    pszresult = str1.StringStr(str2);
    if (pszresult)
    {
        cout << pszresult << endl;
    }
}

void
test_upper_lower(void)
{
    CMyString str1 = "Hello World";

    str1.StringToUpper();
    cout << str1.GetString() << endl;

    str1.StringToLower();
    cout << str1.GetString() << endl;

}

int
main(void)
{
    test_construct();

    test_copy();

    test_cat();

    test_compare();

    test_chr();

    test_pbrk();

    test_strstr();

    test_upper_lower();

    return 0;
}