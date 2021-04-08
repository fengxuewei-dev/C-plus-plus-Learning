#include <iostream>

/*
    引用作为函数的返回值
*/
using namespace std;

// 函数返回的是一个值
int getA();
int getA1();
int getA2(char **pp, int num);

// 函数返回的某一个变量的别名；因此函数的名()可以作为左值
int& getA3();
int& getA4();


void test01();

int main(void){
    test01();
    return 0;
}

// 传递参数的几种方式
int getA(){
    int a = 10;
    return a;
} // 在返回的时候会有一个数据拷贝的动作, 存在一定的缺陷

int getA1(int *a){
    *a = 10;
    return 0;
}

int getA2(char **pp, int num){
    char *p = NULL;
    p = (char*)malloc(num);

    *pp = p;
    return 0;
}

// 函数的返回值是一个引用
// 引用作为函数返回值，不建议将局部函数变量作为一个函数返回值，我们可以返回使用 static 来定义的函数变量。这个时候 该变量是在堆中开辟空间，不是编译器自动回收的。
int& getA3(){
    int a;
    a = 19;
    return a;
}  // 这里编译器默认给了一个 int &temp = a; // temp 为 a 的引用, 将temp作为函数的返回值来返回

int& getA4(){
    static int a = 10;  // 在全局域中开辟空间，在程序运行之后释放空间
    return a;
}

void test01(){
    int a = 0;
    a = getA();
    cout << "a = " << a << endl; 

    // int main_a = 0;
    // main_a = getA3(); // main_a = temp; // 对引用 temp 也就是getA3中的 a 的值进行赋值 

    // cout << "main_a = " << main_a << endl;

    // int &main_a_ref = getA3();  // 这里是 getA3 函数中的局部变量，但是在一个函数调用完成之后，函数内部的变量就会被回收，因此，这里 main_a_ref 也是无效的，出现Segmentation fault (core dumped) 错误

    // cout << "main_a_ref = " << main_a_ref << endl; // 当我们执行第一次的时候，可以发现这个值没有发生什么变换，那是因为在 栈空间中，还没有新的函数入栈，局部变量还没有进行覆盖，我们在执行一次可能就好了
    // cout << "main_a_ref = " << main_a_ref << endl; 

    int &main_a_ref = getA4();  // 这个函数返回的是 一个全局数据区的一个变量，因此在函数调用完成之后不对其进行释放，所以我们可以做下面的操作。
    getA4() = 1000; // 也就是对 static int a; 进行 a = 1000 的操作
    cout << "main_a_ref = " << main_a_ref << endl;
}