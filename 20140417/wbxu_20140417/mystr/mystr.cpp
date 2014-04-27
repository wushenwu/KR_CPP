#include <iostream>
using namespace std;

#include "mystr.h"

int
main(void)
{
    char szdst[32] = "hello world";
    char szsrc[16] = "world";

    cout << mystrcpy(szdst, szsrc) << endl;

    cout << mystrcmp("", "hello") << endl;

    return 0;
}