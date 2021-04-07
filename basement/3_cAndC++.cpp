// c语言中增强的部分
/*
在写代码的时候，出现了警告一定要解决掉，因为编译器对代码做一些默认的优化，但是程序员没有察觉到，
但是在测试的时候，会发现有些内容和我们预想的不一样，这个可能是编译器对代码进行了一定的优化。所以
把警告全部去掉才是一个合格的代码
1. namespace 的引入
2. 实用性增强；
    2.1: c语言的变量需要全部定义在 函数的开头，很少有编译器可以避免这个缺陷；而c++ 是边用边定义
    2.2: 变量的检测能力增强
            在c文件中，定义一个全局变量g_val, 且没有给它进行赋值，那么这个时候再定义一个同名的全局变量，
            int g_val; // 内存分配在 bss 段，全局可访问的数据段n
            int g_val = 20;     // 在data段 ，初始化值的时候将数据放在段内
            上面的代码在c语言中，不能被检测出来， c语言会认为第二行代码是为第一行代码变量的赋值操作 
    2.3: struct 类型增强
    2.4: 对变量和函数的类型进行了一个加强
3. 增加了bool类型
    c中，0 和 非0
    c++ ， 出现了bool t; true; false；当为 bool类型赋值为非零的数，不管是正还是负，都是1；
    当且晋档为其赋值为0的时候为false，大小为 1 个字节
4. 加强了三目运算符号当左值的清醒（见 4.cpp） 返回的是变量引用
5. const 增强
    在 c 语言中，若定义 const int a = 10; 我们可以通过一个指针来修改它的内容，这个时候它就不是常量只读的了，实际是可以被改变的。
6. 对枚举类型对象的使用加强，赋值的时候必须使用枚举变量来为其进行赋值
*/

#include <iostream>

using namespace std;

// c++ 对全局变量的检测能力增强了
// int g_val1;
// int g_val1 = 20;

struct CTEST
{
    char name[64];
    int id;
};


// f(){ // c语言编译的时候不会报错，只会出现一个警告； 在 c++  语言中会报错
//     return 10;
// }

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test01(){
    CTEST st1; // 这个是没有问题的 因为是在c++ 中 会将struct作为一个类进行处理
    st1.id = 20;
}

void test02(){
    bool flag = true;

    if(flag == true){
        std::cout << "flag = (true): " << flag << std::endl;
    }

    flag = false;
    if(flag == false){
        std::cout << "flag = (false): " << flag << std::endl;
    }

    flag = -20;
        std::cout << "flag = (false): " << flag << std::endl;
    
    flag = 20;
        std::cout << "flag = (false): " << flag << std::endl;

        std::cout << "size(bool): " << sizeof flag << std::endl;
}


#if 0
#include <stdio.h>

int g_val;
g_val = 20;
// int g_val = 20;

struct CTEST
{
    char name[64];
    int id;
}; // 需要加分号


void test01();
void test02();

f(){ // c语言编译的时候不会报错，只会出现一个警告
    return 10;
}

int g(int a){
    return 10;
}
int main(void){
    test02();
    return 0;
}

void test01(){
    // c语言中定义结构体对象的时候，在没有使用typedef的时候，必须使用 struct 结构体名字来定义对象，否则编译器可能不能通过
    // 1. 当使用g++ 编译器来编译的时候，会通过，因为使用的 c++ 编译规则来编译的
    struct CTEST st1; // CTEST st1; 报错
    st1.id = 29;   
}
void test02(){
    // g(10, 20, 30, 40);
}
#endif