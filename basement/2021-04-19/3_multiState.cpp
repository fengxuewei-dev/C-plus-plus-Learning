#include <iostream>

using namespace std;


/*
    C++ 中，继承和封装，c都可以做类似的方法来实现，但是多态是c++ 所特有的 特性

    多态，是指的是 当事物接收到一个信号之后，针对相同的对象所产生的动作响应是不同的，那么就称为多态 

    多态发生的三个条件：
    1、需要有继承
    2、在派生类中必须有虚函数重写。若是普通函数重写是进行覆盖，不是多态的概念
    3、父类指针或引用 指向子类对象

    我们在写类的时候，可以写多个接口，这个接口执行内部的某个程序api来实现功能分对象调用...
*/

class A{
    public:
        A(){
            this->num = 0;
        }
        A(double num){
            this->num = num;
        }
        void printNum(){ // 指明该函数是一个虚函数，和之前的额 virtual 是不一样。之前的是在多重继承中，避免有派生类中有多个相同变量存在，出现歧义的情况，设置了一个虚 继承 
        // 是在继承的时候，进行指定。 这个是指明该函数是一个虚函数，这样的话，我们就可以 进行使用多态的概念
        // 一般在 派生类中 也写上 virtual 关键字，来加强程序的可读性.... 只是习惯的问题，在编译的时候不会产生任何影响
            cout << "A::num = " << this->num << endl;

        }
        virtual void run(){
            printNum();
        }
    private:   
        double num;
};

class B : public A{
    public:
        B(double num1, double num2):A(num1){
            this->num = num2;
            this->m = 0;
        }
        
        void printNum(){
            cout << "B::num = " << this->num << endl;
            cout << "B::m = " << this->m << endl;
            m = 20;
            cout << "B::m = " << this->m << endl;
        }
        void run(){
            printNum();
        }
    private:
        double num;
        double m;
};
class C : public A{
    public:
        C(double num1, double num2):A(num1){
            this->num = num2;
        }
        void run(){
            printNum();
        }
        void printNum(){
            cout << "C::num = " << this->num << endl;
        }
    private:
        double num;
};
void printAorB(A *pp){
    cout << "printAorB: " << endl;
    pp->run();         // 在这里不管传入的参数是子类还是父类，都会打印子类中父类的 printNum 方法，没有达到我们预期的想法

    // 这个时候我们可以使用 virtual 关键字来进行指定。。。使用父类指针指向子类对象来进行多态调用
    // 该关键字只需要在 父类中进行指定
}

void test01();
void test02();



int main(void){
    test01();
    return 0;
}

void test01(){
    A aa(20);
    B bb(10, 30);
    C cc(10, 450);
    printAorB(&aa);
    printAorB(&bb);
    printAorB(&cc);
}

void test02(){
    A aa(20);
    B bb(10, 30);
    C cc(40, 70);

    printAorB(&aa);
    printAorB(&bb);
    printAorB(&cc);
}