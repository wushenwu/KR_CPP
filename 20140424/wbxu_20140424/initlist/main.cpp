#include <iostream>
using namespace std;

#include "initlist.h"

int
main(void)
{
    CB t1;

    CB t2(1, 3);

    CA tA(3);
    CB t3(1, tA);
    
    return 0;
}