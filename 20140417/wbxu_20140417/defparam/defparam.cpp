/************************************************************************/
/* 1.定义默认参数，完成函数求圆形面积，参数默认为0.0f，pi定义为常量                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#define  PI  3.14f

float
circle(float r = 0.0f)
{
    return r * r * (PI);
}

int
main(void)
{
    float r = 2.0f;

    cout << circle() << endl;
    cout << circle(r) << endl;

    return 0;
}