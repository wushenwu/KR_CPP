#ifndef FLOAT_H_DCFEE964_3AEE_4c4c_AAAC_44188F00CAF3

#define FLOAT_H_DCFEE964_3AEE_4c4c_AAAC_44188F00CAF3

class CFloat
{
public:
    void SetFloat(long nint, unsigned long nfract) { SetInt(nint); SetFract(nfract); }
    void SetInt(long nint)   { m_nint = nint; }
    void SetFract(unsigned long nfract) { m_nfract = nfract; }

    long GetInt() { return m_nint; }
    unsigned long GetFract() { return m_nfract; }

    CFloat AddFloat(CFloat f1, CFloat f2);
    CFloat SubFloat(CFloat f1, CFloat f2);
   
private:
    long m_nint;
    long m_nfract;
};

#endif
