#include "float.h"

CFloat 
CFloat::AddFloat(CFloat f1, CFloat f2)
{
    long nint1 = f1.GetInt();
    unsigned long nfrac1 = f1.GetFract();

    long nint2 = f2.GetInt();
    unsigned long nfrac2 = f2.GetFract();

    // (-) + (+)
    if (nint1 <= 0 && nint2 >= 0)
    {
        CFloat fsum;
        CFloat ftmp;
        ftmp.SetFloat(-nint1, nfrac1);
        return fsum.SubFloat(f2, ftmp);
    }

    // (+) + (-)
    if (nint1 >= 0 && nint2 <= 0)
    {
        CFloat fsum;
        CFloat ftmp;
        ftmp.SetFloat(-nint2, nfrac2);
        return fsum.SubFloat(f1, ftmp);
    }

    // (-) + (-) or (+) + (+)
    long nintnew = nint1 + nint2;
    unsigned long nfracnew = nfrac1 + nfrac2;
    
    //是否发生了溢出，来判断是否有进位产生
    if (nfracnew < nfrac1 || nfracnew < nfrac2)
    {
        nintnew += 1;
    }

    CFloat ftmp;
    ftmp.SetFloat(nintnew, nfracnew);

    return ftmp;
}


CFloat SubFloat(CFloat f1, CFloat f2)
{
    long nint1 = f1.GetInt();
    unsigned long nfrac1 = f1.GetFract();
    
    long nint2 = f2.GetInt();
    unsigned long nfrac2 = f2.GetFract();

    // (+) - (-)
    if (nint1 >= 0 && nint2 <= 0)
    {
        CFloat fsub;
        CFloat ftmp;
        ftmp.SetFloat(-nint2, nfrac2);
        return fsub.AddFloat(f1, ftmp);
    }

    // (-) - (+)
    if (nint1 <= 0 && nint2 >= 0)
    {
        CFloat fsub;
        CFloat ftmp;
        ftmp.SetFloat(-nint2, nfrac2);
        return fsub.AddFloat(f1, ftmp);
    }
    
    // (+) - (+) or (-) - (-)
    long nintnew = nint1 + nint2;
    unsigned long nfracnew = nfrac1 + nfrac2;

    if (nfrac1 < nfrac2)
    {
        //blabla
    }
    
    CFloat ftmp;
    return ftmp; 
}
    
