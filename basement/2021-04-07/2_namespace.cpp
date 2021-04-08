#include <iostream>


// 一般定义一个全局变量命名规范 为 g_ 开头
int g_a = 10;


// 结构体定义对象的时候，需要加上 struct name t1;
namespace spaceA{
    int g_b = 10;

    namespace spaceB{
        typedef struct TEACHER
        {
            char name[64];
            int id;
            int age;
        }teacher_t;
    }
    namespace spaceC{
        typedef struct TEACHER{
            int id;
            char name[64];
            int age;
        }teacher_t;
    }
}
int main(void){
    using namespace spaceA;
    
    spaceB::teacher_t t1;
    spaceC::teacher_t t2;

    // << 是一种 操作符的重载 重写一个运算符    
    std::cout << spaceA::g_b << std::endl;
    return 0;
}