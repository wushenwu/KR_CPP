#ifndef CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

#define CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

/************************************************************************/
/* 4.ʵ��MyString�г�Ա����MyString* stringcat(MyString *pString)��Ϊһ����ַ�������,
�����������MyNumString(����˼�壬����ֻ�������ִ�),
�����������Ӻ���Ҫ�üӷ�������������23,��34�Ļ�������������������57�ˣ�����2334��
���̲�ʵ�����ǵĶ�̬��                                                                     */
/************************************************************************/

#define REFCOUNT

class CMyString
{
public:
    CMyString();
    CMyString(const char *psz);
    CMyString(const CMyString &str);
    CMyString(int nsize);   //����nsize�ֽڵĿռ�

    virtual ~CMyString();           //virtual, ��Щ��������Ҫ�������������и���

public:
    //�����ַ���
    virtual void SetString(const char *psz);        //virtual
    virtual void SetString(const CMyString &str);   //virtual

    inline const char *GetString(void) const;   //
    
    inline size_t GetLen(void)  const;

    virtual const char *StringCopy(const char *psz);        //virtual
    virtual const char *StringCopy(const CMyString &str);   //virtual

    virtual const char *StringCat(const char *psz);         //virtual
    virtual const char *StringCat(const CMyString &str);    //virtual
    virtual CMyString *StringCat(CMyString *pstr);          //virtual

    /*
    Function: �ַ����Ƚ�
    Return : true ���ַ�����psz���  false �����
    */
    bool StringCompare(const char *psz) const;
    bool StringCompare(const CMyString &str) const;

    /*
    Function: ����һ���ַ�
    Return : ������ڣ��򷵻�ָ���λ�õ�ָ�룬���򷵻�NULL��
             ����StringChr���ص��ǵ�һ�γ��ֵ�λ�ã���StringRchr���ص������һ�γ��ֵ�λ��
    */
    const char *StringChr(int ch) const;
    const char *StringRchr(int ch) const;

    /*
    Function: �����κμ����ַ�, �����κ�һ���ַ���1�����ַ����г��ֵ�λ��
    Return: ����һ��ָ���һ��ƥ��group���κ�һ���ַ���λ�ã� ���δ�ҵ����򷵻�NULL
    */
    const char *StringPbrk(const char *pszgroup) const;
    const char *StringPbrk(const CMyString &str) const;


    /*
    Function: �����Ӵ�
    Return: �ڸ��ַ����в���psz��һ�γ��ֵ���ʼλ�ã�������һ��ָ���λ�õ�ָ�롣
            ���û���ҵ����򷵻�NULL
    */
    const char *StringStr(const char *psz) const;
    const char *StringStr(const CMyString &str) const;

    //���ַ������д�Сдת��
    void StringToUpper(void);
    void StringToLower(void);


//private:
protected:
    void StringInit(void);

#ifdef REFCOUNT
    //���ü������
    void AddRef(void);
    void Release(void);
#endif

//private:
protected:
    char *m_psz;        //�ַ����洢��ַ
    size_t m_nlen;      //�ַ���ʵ��ռ�ó���
    size_t m_nspace;    //������ռ���ܳ���

#ifdef REFCOUNT
    int *m_prefcount;   //���ü���
#endif

};

inline const char *
CMyString::GetString(void) const
{
    return m_psz;
}

inline size_t 
CMyString::GetLen(void) const
{
    return m_nlen;
}

//////////////////////////////////////////////////////////////////////////
//����ΪCMyNumString
//////////////////////////////////////////////////////////////////////////
class CMyNumString: public CMyString
{
public:
    CMyNumString();
    CMyNumString(const char *psz);
    CMyNumString(const CMyNumString &str);

    ~CMyNumString();    //��Ϊ��������죬���µ���Դ�����Բ���Ҳ���ԣ���ʹ�û��������
                          

    //////////////////////////////////////////////////////////////////////////
    //��Ҫ������еĹ��ɸ��ǣ����ܹ��ɶ�̬
    //////////////////////////////////////////////////////////////////////////
    /*
    Function: �������ִ�
    ע��    : ���������ַ���Ϊ���ִ������������
               ���򣬲������ã�����ԭ��
    */
    void SetString(const char *psz);        
    void SetString(const CMyString &str);

    /*
    Function: ������ִ��Ŀ���
    Return  : ���������ַ��������ִ�������п�������ԭ�ַ������ǣ������µ��ַ���
               ����ԭ�ַ������ֲ��䣬����ԭʼ�ַ�����
    */
    const char *StringCopy(const char *psz);       
    const char *StringCopy(const CMyString &str); 
    
    /*
    Function: ������ִ�������
    Return  : ���������ַ��������ִ�����������ִ��ļӷ�����ѧ�����ϵļӷ������������޸ĺ���´�
                ����ԭ���ִ����ֲ��䣬�����ء�
    */
    const char *StringCat(const char *psz);
    const char *StringCat(const CMyString &str);
    CMyString *StringCat(CMyString *pstr);

private:
    /*
    Function:����ַ���psz�Ƿ��Ϊ����
    Return  : true ȫΪ���֣� false ��
    */
    bool CheckNum(const char *psz) const;
    
};


#endif