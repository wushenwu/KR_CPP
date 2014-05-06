/************************************************************************/
/* 2.请为主板类制定好接口，
使得它可以兼容符合此标准接口的声卡，网卡，显卡等
(都用类实现，相应的接口即为函数统一标准即为统一函数)。                                                                     */
/************************************************************************/

#include "interface.h"

int
main(void)
{
    CMainBoard boardobj;

    //not pluged now, access USB
    boardobj.Play();

    //plug and play
    boardobj.Plug(new CAudioCardInterface);
    boardobj.Play();

    boardobj.Plug(new CNetCardInterface);
    boardobj.Play();

    boardobj.Plug(new CGraphCardInterface);
    boardobj.Play();

    return 0;
}