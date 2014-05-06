#include <iostream>
using namespace std;

class CShape
{
public:

    CShape()
    {
        cout << "CShape()" << endl;
    }

    virtual ~CShape()
    {
        cout << "~CShape()" << endl;
    }

    virtual void Test(void) { }
    /*virtual*/ void Draw(void) { cout<< "Draw Shape" << endl; } 
};

class CCircle: public CShape
{
public:

    CCircle() { cout << "CCircle" << endl; }
    ~CCircle() { cout << "~CCircle" << endl; }

    void Draw(void) { cout << "Draw Circle" << endl; }  //会默认的添加成为virtual
};

class CCircleBig: public CCircle
{
public:
    CCircleBig() { cout << "CCircleBig" << endl; }
    ~CCircleBig() { cout << "~CCircleBig" << endl; }

    void Draw(void) { cout << "Draw CircleBig" << endl; }  //因其父类CCircle的Draw已默认的成为virtual
                                                           //所以，仍然有多态性
                                                           
};

class CLine: public CShape
{
public:

    CLine() { cout << "CLine" << endl; }
    ~CLine() { cout << "~CLine" << endl; }

    void Draw(void) { cout << "Draw Line" << endl; }
};

void Draw(CShape *pobj)
{
    pobj->Draw();
}

void Draw(CShape &robj)
{
    robj.Draw();
}

void
test_destruction(void)
{
    CShape *pobj = NULL;    //指向基类的指针或者引用，是必须的

    int nselect = 0;
    cin >> nselect;

    switch (nselect)
    {
    case 0:
        {
            pobj = new CShape;
            break;
        }

    case 1:
        {
            pobj = new CCircle;
            break;
        }

    case 2:
        {
            pobj = new CLine;
            break;
        }
    }

    if (pobj != NULL)
    {
        pobj->Draw();
        delete pobj;    //要想正确的析构，不出现资源泄漏，需要将析构函数也设置为虚函数。
    }
}

void
test1_virtual(void)
{
    CShape shapeobj;
    CCircle circleobj;
    CLine lineobj;

    Draw(&shapeobj);
    Draw(&circleobj);
    Draw(&lineobj);
}

void
test_virtual_continue(void)
{
    CCircleBig circlebigobj;

    Draw(&circlebigobj);
}

/*
在基类、派生类间的转换
*/
void
test_virtual_convert(void)
{
    //单继承，无virtual的情况
    CShape *pshapeobj = NULL;
    CCircle circleobj;
    pshapeobj = &circleobj; 
    //Draw 不为virtual
    pshapeobj->Draw();
    
    //Test 为virtual
    pshapeobj->Test();
    
}

int
main(void)
{
    //test1_virtual();

    //test_destruction();

    //added at 20140501
    test_virtual_continue();    //基类中为virtual, 派生类相应的也会成为virtual

    test_virtual_convert();

    return 0;
}