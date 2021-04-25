#include <iostream>
/*
    面向抽象变成的案例 -- 动物园案例
    1、动物的抽象类 Animal 内部有一个 纯虚函数 voice()
    2、cat类实现该接口
    3、dog类实现该接口

    4、架构函数  -> voice() 属于抽象层的内容，应该出现在 Animal类 中
    5、main函数面向抽象类编程

    多文件形式 .hpp .cpp main
*/

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

using namespace std;

void test01();
void test02();

int main(void){
    test02();
    return 0;
}



void test01(){
    char CatName[64] = "HelloKitty";
    char DogName[64] = "hasiqi";

    Animal *dog = new Dog(DogName);
    printAni(dog);

    Animal *cat = new Cat(CatName);
    printAni(cat);


    printAni(new Cat(CatName));
}


void test02(){

    string CatName = "HelloKitty";
    string DogName = "hasiqi"; // 调用 c_str 方法，返回的数据是 const char *

    Animal *dog = new Dog(DogName.c_str());
    printAni(dog);
    Animal *cat = new Cat(CatName.c_str());
    printAni(cat);
}