#include <iostream>
using namespace std;

#include "CMyString.h"

void
test_assign(void)
{
    CMyString str1 = "hello world";
    str1 = "hello ";                //试图构造，然后memcpy

    (str1 = "hello") = "world";

    CMyString str2;
    CMyString str3 = "hello";
    str2 = str3;    //浅拷贝，memcpy

    (str2 = str1) = str3;
}

void
test_cat(void)
{
    CMyString str1 = "hello";

    str1 + " world";

    CMyString str2 = " C++";
    str1 + str2;

    CMyString str3 = "hello" + str2;
}

void
test_cat_assign()
{
    CMyString str1 = "hello";

    str1 += "world";

    CMyString str2 = "C++";
    str1 += str2;
}

void
test_index(void)
{
    CMyString str1 = "hello";

    str1[0] = 'H';
}

void
test_equal(void)
{
    CMyString str1 = "hello";

    if (str1 == "hello")
    {
        cout << "equal" << endl;
    }

    if (str1 == "Hello")
    {
        cout << "equal" << endl;
    }

    CMyString str2 = "hello";
    if (str1 == str2 )
    {
        cout << "equal" << endl;
    }

    if ("hello" == str2)
    {
        cout << "equal" << endl;
    }
}

void
test_nonequal(void)
{
    CMyString str1 = "hello";
    
    if (str1 != "hello")
    {
        cout << "nonequal" << endl;
    }
    
    if (str1 != "Hello")
    {
        cout << "nonequal" << endl;
    }
    
    CMyString str2 = "Hello";
    if (str1 != str2 )
    {
        cout << "nonequal" << endl;
    }

    if ("Hello" != str1)
    {
        cout << "nonequal" << endl;
    }
}

void
test_bigger(void)
{
    CMyString str1 = "hello";
    
    if (str1 > "gello")
    {
        cout << "bigger" << endl;
    }
    
    if (str1 > "iello")
    {
        cout << "bigger" << endl;
    }
    
    CMyString str2 = "gello";
    if (str1 > str2 )
    {
        cout << "bigger" << endl;
    }

    if ("hello" > str2)
    {
        cout << "bigger" << endl;
    }

}

int
main(void)
{
    test_assign();  // =

    test_cat();    // +

    test_cat_assign(); // +=

    test_index();   // []

    test_equal(); // ==

    test_nonequal(); // !=

    test_bigger();

    return 0;
}