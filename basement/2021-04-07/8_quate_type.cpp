#include <iostream>


using namespace std;

/*
    引用的本质： 引用本质是一个常量指针
    int array[10] 在 栈中开放10个int类型的地址空间，但是 array 是地址，保存在常量区“符号表”
*/
struct typeA
{
    int &a;
};
struct typeB
{
    int *a;
};

typedef struct student
{
    int id;
    char name[64];
}stu;


void modify(int *const p);

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test01(){
    // 求出各个结构体的大小
    // 引用所占用的大小和指针大小是一致的
    // sizeof(struct typeA): 8
    // sizeof(struct typeB): 8

    cout << "sizeof(struct typeA): " << sizeof(struct typeA) << endl;
    cout << "sizeof(struct typeB): " << sizeof(struct typeB) << endl;


    int  a = 10;
    int &rec = a;   // 引用必须要初始化； 常量也要必须初始化，引用可能是一个常量，但是引用又是一种指针，故，引用应该是一种 常量指针（常指针） int const *p = NULL;  因此，引用实现底层就是一个常指针
    int const *p = &a; // 这里 指针 p 是不能修改地址指向的，同时在初始化的时候必须为其初始化。
}


// 这里的指针 p 是一个常量指针，因为 这里const 修饰的是指针 
// 这个 指针 p 是常量的，因此其内部包含的地址是不可以修改的， 但是这个地址内的数据是可以被修改的

// 若这里的 int *const 写成了  int const *p  == const int *p 是等价的，这个时候是指针常量，不能使用指针来修改该变量的值
void modify(int *const p){   // void modify(int &p); 是一致的。当我们将引用作为函数参数的时候，编译器会替我们将实参取地址给引用 // int *const p = &a; 同时这个 p 指针也在那个符号表中存储
    *p = 20; // p = 30; // 当我们对引用进行赋值的时候，编译器又对我们隐藏了 * 的操作
}

void test02(){
    stu s1 = {20, "fxw"};
    modify(&s1.id);
}