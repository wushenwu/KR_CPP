#ifndef DERIVE_H_2F123D3A_817D_4d86_80B3_8CAFFD34A9EA

#define DERIVE_H_2F123D3A_817D_4d86_80B3_8CAFFD34A9EA

class CBase
{
public:
    CBase() { }
    CBase(const CBase &obj)
    {
        m_npublicdata = obj.m_npublicdata;
    }

public:
    void SetPublicData(int ndata) { m_npublicdata = ndata; }
    void SetPublicData(void) { m_npublicdata = 0; } //just 4 fun

public:
    int GetPublicData() { return m_npublicdata; }
    int m_npublicdata;

protected:
    int GetProtectedData() { return m_nprotecteddata; }
    int m_nprotecteddata;

private:
    int GetPrivateData() { return m_nprivatedata; }
    int m_nprivatedata;
};

class CPublic: public CBase
{
public:     //��CBase�еĳ�Ա����Ȼ������private�ˣ��������������Ը������������
    CBase::GetProtectedData;
    CBase::m_nprotecteddata;

public:
    int GetPublicDataB()    //�������������Ĺ���
    {
        GetPublicData();
        GetProtectedData();
        //GetPrivateData();   //˽�г�Ա���޷����̳е�
    }
    
};

class CProtected: protected CBase
{

};

class CPrivate: private CBase
{

};

class CHide: public CBase
{
public:
    void SetPublicData(int ndata) { m_npublicdata = ndata; }
    int m_npublicdata;

};

class CConvert: public CBase
{
public:
    CConvert() {}
    CConvert(const CConvert &obj)
    {
        m_npublicdata = obj.m_npublicdata;
    }

public:
    int m_npublicdata;
};

#endif
