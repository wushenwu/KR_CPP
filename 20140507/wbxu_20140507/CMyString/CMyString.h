#ifndef CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

#define CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

#define REFCOUNT

/*
Do like this for fatal error C1001: INTERNAL COMPILER ERROR
    http://blog.sciencenet.cn/blog-573895-618943.html 
    
    ������ǰ������ͬʱ����ȫ�ֺ�����
    �Ժ��������ʵ�֡�
*/

class CMyString;
CMyString operator+ (const char *psz, const CMyString &obj);    //����ֵ����Ϊ��ʱ���Ǳ����
// bool operator== (const char *psz, const CMyString &obj);     //�Ǳ���
// bool operator!= (const char *psz, const CMyString &obj); 
// bool operator> (const char *psz, const CMyString &obj);

class CMyString
{
public:
    CMyString();
    CMyString(const char *psz);
    CMyString(const CMyString &str);

    virtual ~CMyString();

public:     //������������
    CMyString & operator= (const char *psz);
    CMyString & operator= (const CMyString &obj);

    CMyString operator+ (const char *psz);
    CMyString operator+ (const CMyString &obj);
    friend CMyString operator+ (const char *psz, const CMyString &obj)
    {
        return CMyString(psz).StringCat(obj);
    }
    

    CMyString& operator+= (const char *psz);
    CMyString& operator+= (const CMyString &obj);

    char & operator[] (int nIndex);

    bool operator== (const char *psz);
    bool operator== (const CMyString &obj);
    friend bool operator== (const char *psz, const CMyString &obj)
    {
        if (0 == strcmp(psz, obj.m_psz))
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool operator!= (const char *psz);
    bool operator!= (const CMyString &obj);
    friend bool operator!= (const char *psz, const CMyString &obj)
    {
        if (strcmp(psz, obj.m_psz))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator> (const char *psz);
    bool operator> (const CMyString &obj);
    friend bool operator> (const char *psz, const CMyString &obj)
    {
        if (strcmp(psz, obj.m_psz) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    //�����ַ���
    virtual void SetString(const char *psz);
    virtual void SetString(const CMyString &str);

    inline const char *GetString(void) const;   //
    
    inline size_t GetLen(void)  const;

    virtual CMyString &StringCopy(const char *psz);
    virtual CMyString &StringCopy(const CMyString &str);

    virtual CMyString &StringCat(const char *psz);
    virtual CMyString &StringCat(const CMyString &obj);

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


protected:
    void StringInit(void);

#ifdef REFCOUNT
    //���ü������
    void AddRef(void);
    void Release(void);
#endif

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
    
    ~CMyNumString();   
    
    
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
    CMyString &StringCopy(const char *psz);       
    CMyString &StringCopy(const CMyString &str); 
    
    /*
    Function: ������ִ�������
    Return  : ���������ַ��������ִ�����������ִ��ļӷ�����ѧ�����ϵļӷ������������޸ĺ���´�
    ����ԭ���ִ����ֲ��䣬�����ء�
    */
    CMyString &StringCat(const char *psz);
    CMyString &StringCat(const CMyString &obj);
    
private:
/*
Function:����ַ���psz�Ƿ��Ϊ����
Return  : true ȫΪ���֣� false ��
    */
    bool CheckNum(const char *psz) const;
    
};


#endif