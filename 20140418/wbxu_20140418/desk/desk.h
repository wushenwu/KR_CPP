#ifndef DESK_H_41179F1C_6A81_4a67_BD45_A53E9647F1AE

#define DESK_H_41179F1C_6A81_4a67_BD45_A53E9647F1AE

#include <string.h>

class CDesk
{
public:
    enum COLOR {RED, GREEN, BLUE, YELLOW};

public:
    void SetDesk(float flen, float fwidth, float fheight, COLOR enucolor);
    void SetLen(float flen);
    void SetWidth(float fwidth);
    void SetHeight(float fheight);
    //void SetColor(char *pszcolor) { strncpy(m_szcolor, pszcolor, 15); m_szcolor[15] = '\0'; }
    void SetColor(COLOR enucolor);

public:
    float GetLen();
    float GetWidth();
    float GetHeight();
    COLOR GetColor();

private:
    float m_flen;
    float m_fwidth;
    float m_fheight;
    //char m_szcolor[16];     //或许写成枚举类型会更好
    enum COLOR m_enucolor;
};

#endif
