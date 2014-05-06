#include "CStudManage.h"

int
main(void)
{
    int nresult = SUCCESS;

    CStudManage *psystem = CStudManage::CreateSystem();
    nresult = psystem->Run();
    psystem->End();
    return nresult;
}

