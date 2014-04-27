#include <iostream>
using namespace std;

/*
替代C无参宏
*/
void
test_macro(void)
{
    const int NUM = 3;
    
    *(int *)&NUM = 2;         //try to change NUM by pointer, ok, success.
    
    //替代无参宏
    cout << NUM + 2 << endl;  // when compiling, will replace into " cout << 3 + 2 << endl;
    // so 5, not 4.
    
    int ntest = *(int *)&NUM; //ntest will be the already changed NUM, that is 2.
    cout << ntest << endl;
}

void
test_change(void)
{
    char *p1 = "hello";     //hello在全局数据区
    p1[0] = 'w';            //试图更改全局数据区数据，在运行时出错。

    const char *p2 = "hello";
    //p2[0] = 'w';            //p2所指向的内容不能更改，在编译时就报错。
}

void
test_convert(void)
{
    char *p1 = "hello";
    const char *p2 = "hello";

    p2 = p1;    //ok. 试图将非严格检查的p1转换为严格类型的p2.
    
    p1 = p2;    //error, 试图将严格类型的p2转换为非严格类型的p1, 这可能导致对p2的修改。不可
}

int
main(void)
{
    //test_macro();

    //test_change();

    test_convert();

    return 0;
}