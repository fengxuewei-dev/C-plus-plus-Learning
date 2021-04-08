/*
    函数重载： 一个函数应该需要
        函数返回值： 不参与重载的条件
        函数形参列表（参数类型、参数个数、参数顺序）

        定义函数重载的时候，不要写默认参数，为了避免调用出现函数歧义
        出现占位符号也可以

        函数重载的时候，会有一个匹配的规则；当有一个完全匹配的规则的时候，会调用完全匹配的函数；但没有完全匹配但可以通过隐式转换匹配的，就通过隐式转换
    
    在c++底层中，c++利用name mangling(倾轧)技术，来改函数名，区分参数 不同的同名函数
    实现原理：用 void char int float long double 用 v c i f l d 来进行表示
    每个函数对应一个地址
*/
#include <iostream>

using namespace std;

void test01();

void fun1(int a, int b); // 底层是 void fun1_ii(int a, int b)
// void fun1(int a, int b, int);

// 在函数声明的时候，不能进行默认参数的 声明
void fun1(int a, int b, int c); // 底层是 void fun1_iii(int a, int b, int c)

int main(void){
    test01();
    return 0;
}

void fun1(int a, int b){
    cout << "fun1" << endl;
}
// void fun1(int a, int b, int){
//     cout << "fun2" << endl;
// }
void fun1(int a, int b, int c = 20){
    cout << "fun2" << endl;
}
void test01(){
    fun1(10, 20, 30);  
}