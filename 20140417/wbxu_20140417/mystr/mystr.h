#ifndef MYSTR_H_EC16A3C2_EE91_4bd9_9F4D_B5A396A1299D

#define MYSTR_H_EC16A3C2_EE91_4bd9_9F4D_B5A396A1299D

/*
2.定义内联函数，完成字符串的复制和比较
*/

inline char *
mystrcpy(char *pszdst, const char *pszsrc)
{
    char *psz = pszdst;
    while ((*psz++ = *pszsrc++) != '\0')
    {
        ;
    }

    return pszdst;
}

inline int
mystrcmp(const char *psz1, const char *psz2)
{
    while (*psz1 != '\0'
            && *psz2 != '\0'
            &&*psz1++ == *psz2++
            )
    {
        ;
    }

    return *psz1 - *psz2;
}

#endif
