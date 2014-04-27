#include <iostream>
using namespace std;

#include "refcount.h"

/*
对用静态数据成员进行引用计数的测试
注意：
1) 因静态数据成员在所有对象间共享，所以仅适用于单对象的情况（仅能产生一个对象）
2) 浅拷贝，相当于memcpy,不会更新引用计数，会出错
*/
void
test_static(void)
{
    CStudent stu1;          //默认无参构造，尚无资源申请，引用计数应该为0
    stu1.SetName("hello");  //申请资源，引用计数加1

    CStudent stu2 = stu1;   //拷贝构造，对资源的引用计数加1

    CStudent stu3;
    //stu3 = stu1;            //浅拷贝，不进行引用计数更新，出错暂无法解决

    CStudent stu4(2, "world"); //进行新资源的申请，静态数据成员引用计数开始失效。

}

/*
以资源为中心的引用计数

每对象进行创建时，相应的创建其引用计数
每对象析构时，相应的减小其引用计数
            当减至0，无对象再引用该资源时，释放该资源，同时释放该引用计数器

新对象引用已有资源时，进行引用计数增加

注意： 仍然存在浅拷贝，不更新引用计数的问题， 暂无法解决
*/
void
test_ref(void)
{
    CStudent stu1;          //默认无参构造，尚无引用计数器
    stu1.SetName("hello");  //创建资源，创建引用计数器

    CStudent stu2 = stu1;   //拷贝构造，增加引用计数

    CStudent stu3(1, "world"); //创建新资源，创建新引用计数器
    
    CStudent stu4(stu3);    //拷贝构造，增加引用计数

    //stu4 = stu1;            //浅拷贝，引用计数开始失效

    stu4.SetName("stu4");   //一个对象修改资源，影响所有共享该资源的对象
                            //当然了，这里因为我们SetName的实现原因，相当于Copy On Write了，所以没有看到影响

}

int
main(void)
{
    test_static();     //用静态数据成员进行引用计数

    test_ref();        //以资源为中心的引用计数

    return 0;
}