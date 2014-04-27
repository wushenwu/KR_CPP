#ifndef COMPUTER_H_7217FA20_3973_4c9f_9D63_9A9EC225B358

#define COMPUTER_H_7217FA20_3973_4c9f_9D63_9A9EC225B358

class CComputer
{
public:
    enum BRAND {LENOVO, DELL, SUNGSANG};

public:
    void SetComputer(float fprice, float fsize, BRAND enubrand);
    void SetPrice(float fprice);
    void SetSize(float fsize);
    void SetBrand(BRAND enubrand);

public:
    float GetPrice();
    float GetSize();
    BRAND GetBrand();

private:
    float m_fprice;
    float m_fsize;
    BRAND m_enubrand;    
};

#endif