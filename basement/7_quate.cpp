/*
 引用：
 int a = 10
 当定义一个变量的时候，系统会在栈空间中为其分配一个内存空间(这个是4个字节)，

 我们可以使用 typedef 为数据类型起别名
    typedef int myInt;
 那么我们可以为 变量名 起别名吗？ --- 引用


 1. 引用一经定义，不可以改变
 2. 引用在声明的时候必须进行初始化， 和常量类似
 3. 可以对引用再起引用
 4. 数据类型 & : 引用，其他地方都是地址

 值传递，需要考虑内存的大小，
 指针传递，只需要传递一个首地址就可以了
 引用传递，传递一个地址就可以了
*/
#include <iostream>

void change_value(int&);
void swap(int&, int&);
void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test01(){
    int a = 20;
    int b = 30;

    int *p = &a;
    *p = 30;

    p = &b; 
    *p = 40;

    int &re = a;      // 引用 re 是 a 的引用
    re = 50;

    std::cout << "a = " << a << std::endl; 


    re = b;
    re = 50;
    std::cout << "re = " << re << std::endl; 

    int &rea2 = a;
}

void change_value(int& p){
    p = 20;
}

void test02(){
    int a = 30;
    change_value(a);

    std::cout << "a = " << a << std::endl;
}
void test03(){
    int a = 30;
    int b = 20;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    swap(a, b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}