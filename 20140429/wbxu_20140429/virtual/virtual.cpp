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
    virtual void Draw(void) { cout<< "Draw Shape" << endl; }
};

class CCircle: public CShape
{
public:

    CCircle() { cout << "CCircle" << endl; }
    ~CCircle() { cout << "~CCircle" << endl; }

    void Draw(void) { cout << "Draw Circle" << endl; }
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


int
main(void)
{
    test1_virtual();

    test_destruction();

    return 0;
}