#include <iostream>


/*
    const int a;
    int const a; 和上面是等价的，表示a是一个常量，数据存放在栈中

    const int *b;   // 指针在 32 位系统中 占位 4个字节，64位是8个字节，地址的长度不同，这个*修饰的 const int; 如果这个指针指向一个区域，那么这一块儿区域是不可以通过指针来修改的，是因为这个 const 修饰的是int 数据类型，所以它指向的地址是内容是不可以修改的，但是这个指针是 int * , 可以指向其他的位置
    int const *b;   // 这个时候，const 修饰的指针，也就是说这个指针也就是指向的地址是不可以修改的，但是数据内容是可以修改的

    const int const *c;//结合上面的两个的特定，都不能进行修改
*/
void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    const int a = 10; // 这个时候不能通过变量名字来修改，但是指针是无敌的，我们可以通过地址也就是指针来修改.
    int array_a[a] = {0}; // 在c++ 中 const 常量是一个真常量，所以可以为数组分配指定大小的空间
    printf("a = %d\n", a);

    int *p = (int*)&a;        // 在c++中会报错

    *p = 27;

    printf("a = %d\n", a);      // 但是 a 的值没有改变，代表了 a 是真的常量
    printf("*p = %d\n", *p);    // 这个值改变了

    /*
    当编译器在编译代码的时候，若发现 a 是常量，并没有为其在栈中开辟一个空间，而是在常量区有一个 “符号表” (存放 的是键值对key-value)，创建一个表格其中的key字段存放 a， value字段存放 10
    在使用a的时候，当发现 a 的出现， 就把它当做10处理，a并没有所谓的空间和地址；和宏定义类似，但是宏定义是在预处理阶段进行替换，但是这个是在 编译阶段

    .c -- 预处理（宏处理展开） -- 编译(做一些词法分析和语法分析) -- 链接

    但是  int *p = (int*)&a;  a 没有地址，但是在这里对常量 a 进行取地址，
    当 定义了 *p 的是，系统会在 栈内为其 开辟一个新的空间 ；若对一个常量取地址，编译器会临时开辟一个空间，让这个指针来指向临时空间的地址.
    所以 出现 a 的值没有出现变换，但是 *p 的值发生了变化，因为 *p 改变的是临时开辟的变量

    保证了 C++ 中 const 是一个真正的常量，而C语言中的是一个假常量
    */
}