#include <iostream>
#include <cstring>

/*
面向对象和面向过程的一个区别：
1、面向对象 它是 实现对象来驱动函数的执行；在面向过程中，是函数来驱动对象来实现功能
*/

using namespace std;

class Dog{
    public:
        char name[64];
        void eat(const char * food){ // 这里需要将 函数的类型指定为一个常量指针，也就是在函数内部不能对 传入的形参来进行更改内容，因为在下面调用的时候，我们使用的是字符串常量
            cout << name << " eat " << food << endl;
        }
};

void eat(class Dog & dog, const char * food){
    cout << dog.name << " eat " << food << endl;
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Dog dog;
    strcpy(dog.name, "dog");

    dog.eat("food");    // 对象来驱动函数（动作）
    eat(dog, "food");   // 函数（动作）来驱动动作
}