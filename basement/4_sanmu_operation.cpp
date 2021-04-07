// 三目运算符
/*
    左值和右值的概念
    当一个变量可以存在等号的左侧，来充当左值的时候，那么这个变量一定是可以被修改的

    三目运算符返回的是一个常量，是一个数值，这个是数值是不能被修改的，所以三目运算符是不能充当左值的
*/

#include <iostream>

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    int a = 10;
    int b = 20;

    int c = 0;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    c = a > b ? a : b;


    // c++ 中 三目运算符 会将变量返回，返回的是引用；在c中返回的是数值
    // (a > b ? a : b) = 50; // 这个的时候是可以的
    *(a > b ? &a : &b) = 50;    // 这个也是可以的

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}


#if 0

// c code
void test02(){
    
    int a = 10;
    int b = 20;

    int c = 0;
    printf("a = %d \tb = %d \n", a, b);

    c = a > b ? a : b;

    // (a > b ? a : b) = 50; // 等号的左侧是cpu计算出来的一个值，位于临时保存的寄存器内部，所以没有什么地址的概念，但是我们也可与将其作为左值 （在C++的时候发现是可以的, but it is not in c）
    *(a > b ? &a : &b) = 50;    // 这个也是可以的

    printf("a = %d \tb = %d \n", a, b);
}

#endif