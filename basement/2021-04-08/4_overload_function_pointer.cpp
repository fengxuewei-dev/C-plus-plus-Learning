/*
    函数重载和函数指针
    
*/
#include <iostream>

using namespace std;

// 函数指针的定义
void fun1(int a, int b){
    cout << "fun1" << endl;
}

// 1、定义一种函数类型
typedef void(MY_FUNCTION)(int,int); // MY_FUNCTION 就是一个函数指针


// 2、定义一个指向这种函数类型的指针类型
typedef void(*MY_FUNCTION_P)(int, int);

void test01();

void fup(int a, int b){
    cout << "fup(int , int)" << endl;
}
void fup(int a, int b, int c){
    cout << "fup(int, int, int)" << endl;
}

int main(void){
    test01();
    return 0;
}

void test01(){
    // 1、
    MY_FUNCTION *my = NULL;

    my = fun1;

    my(10, 20); //    (*my)(10, 20);

    // 2、
    MY_FUNCTION_P my_p = fun1;
    my_p(10, 20);

    // 3. 
    void(*fp3)(int, int) = NULL;
    fp3 = fun1;

    fp3(10, 20);


    // 
    void(*fp4)(int, int) = NULL; // 指定了函数的参数列表的个数
    fp4 = fup;

    fp4(10, 20);
    // fp4(10, 20, 30);    // 报错， 函数指针不支持重载
    

    // 实际上在给函数指针赋值的时候，就已经发生函数重载匹配了
    // 在调用函数指针的时候，所调用的函数是已经固定好了的
    // 函数重载的时候，会有一个隐士转换，但是在函数指针调用的时候，是严格意义匹配的，因为指针类型是要完全匹配的
}