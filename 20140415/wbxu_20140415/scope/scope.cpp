#include <iostream.h>

#define for if (0) {} else for         //强制限制为块作用域，以避免不同编译器下作用域问题

//#define for if (1) for

void
test_switch()
{
    int nselect = 0;
    
    switch (nselect)
    {
    case 0:
        {
            int tmp = 0;
            cout << tmp;
            break;
        }     
        
    case 1:
        {
            int tmp = 3;
            cout << tmp; 
            break;
        }        
    }
}

void
test_for()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }
}

int
main(void)
{
    test_switch();

    test_for();

    return 0;
}
