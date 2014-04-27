#include "computer.h"

void CComputer::SetComputer(float fprice, float fsize, BRAND enubrand)
{
    SetPrice(fprice);
    SetSize(fsize);
    SetBrand(enubrand);
}

void CComputer::SetPrice(float fprice)
{
    m_fprice = fprice;
}

void CComputer::SetSize(float fsize)
{
    m_fsize = fsize;
}

void CComputer::SetBrand(BRAND enubrand)
{
    m_enubrand = enubrand;
}

float CComputer::GetPrice()
{
    return m_fprice;
}

float CComputer::GetSize()
{
    return m_fsize;
}
 
CComputer::BRAND CComputer::GetBrand()
{
    return m_enubrand;
}