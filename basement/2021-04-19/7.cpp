#include <iostream>

using namespace std;

/*
    面向接口的编程：函数指针 == 回调函数

    函数指针：
        函数的返回值、函数的参数列表（形参个数、类型、顺序） 都决定着函数的类型，函数名不是决定，它只是一个指向函数入口的指针而已
        1、定义一个函数类型
        2、定义一个函数指针(不推荐)
        3、直接定义一个函数指针类型

    函数指针的意义：
        当存在多个不同名，但是函数类型是一样的多个函数，那么我们就可以使用一个接口来将他们都调用起来
*/

// c 业务层
int func(int a, int b){
    cout << "func,..." << endl;
    return 0; 
}


int func2(int a, int b){
    cout << "func,..." << endl;
    return 0; 
}


int func3(int a, int b){
    cout << "func,..." << endl;
    return 0; 
}


// 公用的接口
void My_Func( int(*fp)(int, int), int a, int b ){
    fp(a, b);
}

// 1. 定义一个函数类型
typedef int (FUNC)(int, int);

// 2、定义一个函数指针
typedef int(*FUNC_P)(int, int);

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test02(){
    My_Func(func2, 20, 30);
}
void test01(){

    // 1. 
    FUNC *fp = NULL;   
    fp = func;  
    // 赋值，如果 fp = func() 成了函数的调用 此时 fp指向上面函数的入口地址 (*fp)(10,20) === fp(10, 20)
    fp(10, 20);

    // 2.
    FUNC_P fp2 = NULL;
    fp2 = func;
    fp2(10,20);

    // 3、方法3
    int (*fp3)(int , int) = NULL;
    fp3 = func;
    fp3(10, 20);
}