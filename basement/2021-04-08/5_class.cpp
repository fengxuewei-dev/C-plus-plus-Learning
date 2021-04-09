#include <iostream>
/*
    类的内部存在 getter\setter 方法
    访问权限：private、protected、public
    在类的内部，当数据成员没有指定访问权限的时候，默认为 private

    c++ 中，结构体和类是一样的，唯一的区别就是内部的访问权限是不一样的
    一个结构体默认的访问权限是一个 public，在类中是 private
*/
using namespace std;

class Hero{
public:
    int year;   // 默认为 private 权限的
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Hero h1;
    h1.year = 0;  
}