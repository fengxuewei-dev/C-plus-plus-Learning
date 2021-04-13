/*
    函数重载：为相同的函数提供多个接口
    操作符重载：
        给一个操作符的另外含义 对于一些自定义的数据类型进行运算

        1. 使用全局函数实现
        2. 使用 类函数实现
*/
#include <iostream>

using namespace std;

class Complex{
    // 1
    // friend Complex operator+(Complex& c1, Complex &c2);

    public:
        Complex(double a, double bi){
            this->a = a;
            this->bi = bi;
        }

        // 2.
        // Complex operator+(const Complex& c1){ // 运算符重载后面的形参定义不能使用常量引用
        Complex operator+(Complex& c1){
            Complex temp(this->a +c1.a, this->bi +c1.bi);
            return temp;
        }
        Complex(const Complex& c1){
            cout << "complex (const Complex & c1)" << endl;
            this->a = c1.a;
            this->bi = c1.bi;
        }
        void printComplex(){
            cout << this->a << " + " << this->bi << "i" << endl;
        }
    private:
        double a;
        double bi;
};


// 1. operator 是一种操作符，和后面+不能有空格 operator+ 是该函数的函数名字
// Complex operator+(Complex& c1, Complex &c2){
//     Complex temp(c1.a +c2.a, c1.bi +c2.bi);
//     return temp;
// }

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Complex c1(12, 23);
    Complex c2(11, 32);

    // Complex c3 = c1 + c2; // 又会去全局找，又会去类中找，只能存在一个，否则会出现二义性
    // 1.
    // Complex c3 = c1 + c2;
    // Complex c3 = operator+(c1, c2); // c1 和 c2 传入的顺序和运算符左值和右值是一致的 （全局函数）
    
    // 2. 
    Complex c3 = c1 + c2; // c1.operator+(c2);

    c3.printComplex();
}