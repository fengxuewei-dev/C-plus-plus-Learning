/*
    枚举的类型
*/

#include <iostream>

enum Season{
    spring = 0,
    summer,
    autumn,
    winter
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    enum Season s = spring; // c++ 中必须通过枚举变量来为 这个枚举类型赋值，不能通过 常量来为其进行赋值
}