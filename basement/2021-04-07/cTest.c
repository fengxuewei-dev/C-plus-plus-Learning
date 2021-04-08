#include <stdio.h>

// int g_val;
// int g_val = 20;

struct CTEST
{
    char name[64];
    int id;
}; // 需要加分号


enum Season{
    spring = 0,
    summer,
    autumn,
    winter
};

void test01();
void test02();
void test03();
void test04();

// f(){ // c语言编译的时候不会报错，只会出现一个警告
//     return 10;
// }

int g(int a){
    return 10;
}
int main(void){
    test04();
    return 0;
}

void test01(){
    // c语言中定义结构体对象的时候，在没有使用typedef的时候，必须使用 struct 结构体名字来定义对象，否则编译器可能不能通过
    // 1. 当使用g++ 编译器来编译的时候，会通过，因为使用的 c++ 编译规则来编译的
    struct CTEST st1; // CTEST st1; 报错
    st1.id = 29;   
}
void test02(){
    
    int a = 10;
    int b = 20;

    int c = 0;
    printf("a = %d \tb = %d \n", a, b);

    c = a > b ? a : b;

    // (a > b ? a : b) = 50; // 等号的左侧是cpu计算出来的一个值，位于临时保存的寄存器内部，所以没有什么地址的概念，但是我们也可与将其作为左值 （在C++的时候发现是可以的,但是早在c中是不可以的）
    *(a > b ? &a : &b) = 50;    // 这个也是可以的

    printf("a = %d \tb = %d \n", a, b);
}

void test03(){
    const int a = 10; // 这个时候不能通过变量名字来修改，但是指针是无敌的，我们可以通过地址也就是指针来修改.
    // int array_a[a] = {0}; // 报错，说明编译器编译的时候，认为a是一个加了const修饰的变量而已
    printf("a = %d\n", a);

    int *p = &a;        // 会报一个警告，这是一个不安全的指针，将一个不安全的指针指向一个安全的变量，

    *p = 27;

    printf("a = %d\n", a);
}
void test04(){
    enum Season s = 0;

    /*
        这个枚举类型内部列举了四种情况，但是如果在开发项目的时候，
        需要枚举的类型有成百上千，那么如果我们要判断一个变量，我们需要去数自己选择的对吗，我们一般习惯，每10个，或者每多少个，该枚举项后面写一个 = xx

        在c中，可以通过常量来为枚举类型的对象赋值，但是这个会出现上面的弊端，在c++中，默认我们必须使用枚举变量来为枚举类型对象进行赋值，方便用户查看或者编写
    */

    if(s == spring){
        
    }
}