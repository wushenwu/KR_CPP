#ifndef CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

#define CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

class CMyString
{
public:
    CMyString();
    CMyString(const char *psz);
    CMyString(const CMyString &str);

    ~CMyString();

public:
    //�����ַ���
    void SetString(const char *psz);
    void SetString(const CMyString &str);

    inline const char *GetString(void);
    
    inline size_t GetLen(void);

    const char *StringCopy(const char *psz);
    const char *StringCopy(const CMyString &str);

    const char *StringCat(const char *psz);
    const char *StringCat(const CMyString &str);

    /*
    Function: �ַ����Ƚ�
    Return : true ���ַ�����psz���  false �����
    */
    bool StringCompare(const char *psz);
    bool StringCompare(const CMyString &str);

    /*
    Function: ����һ���ַ�
    Return : ������ڣ��򷵻�ָ���λ�õ�ָ�룬���򷵻�NULL��
             ����StringChr���ص��ǵ�һ�γ��ֵ�λ�ã���StringRchr���ص������һ�γ��ֵ�λ��
    */
    char *StringChr(int ch);
    char *StringRchr(int ch);

    /*
    Function: �����κμ����ַ�, �����κ�һ���ַ���1�����ַ����г��ֵ�λ��
    Return: ����һ��ָ���һ��ƥ��group���κ�һ���ַ���λ�ã� ���δ�ҵ����򷵻�NULL
    */
    char *StringPbrk(const char *pszgroup);
    char *StringPbrk(const CMyString &str);


    /*
    Function: �����Ӵ�
    Return: �ڸ��ַ����в���psz��һ�γ��ֵ���ʼλ�ã�������һ��ָ���λ�õ�ָ�롣
            ���û���ҵ����򷵻�NULL
    */
    char *StringStr(const char *psz);
    char *StringStr(const CMyString &str);

    //���ַ������д�Сдת��
    void StringToUpper(void);
    void StringToLower(void);


private:
    void StringInit(void);

private:
    char *m_psz;        //�ַ����洢��ַ
    size_t m_nlen;      //�ַ���ʵ��ռ�ó���
    size_t m_nspace;    //������ռ���ܳ���
};

inline const char *
CMyString::GetString(void)
{
    return m_psz;
}

inline size_t 
CMyString::GetLen(void)
{
    return m_nlen;
}


#endif