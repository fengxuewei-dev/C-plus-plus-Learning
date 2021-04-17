#include <iostream>

using namespace std;

/*
    C++ 中不允许重载的运算符有； . .* :: ?:
        1、点运算符 (l1.getX()) 
        2、.*  ==> 
                class A{
                    char *p
                };
                A a;
                a.*p ===> *(a.p)

        3. 域解析符
        4、三目运算符

        = 和 & 等号和取地址一般不需要重载

        && 和 || 不建议进行重载。。。

    重载不能 改变操作运算符的操作个数
    不能改变运算符的优先级
    不能改变运算符的结合性
    操作符重载不能有默认参数 和上面一点冲突
    重载操作符函数形参中至少要有一个自定义的数据类型

    保持该运算符的含义和操作标准数据类型的含义是一致的。
    可以是类的友元函数，类的成员函数，也可以是普通函数
*/
class Complex{
    // 1.
    // friend Complex operator+(Complex& c1, Complex& c2);
    public:
        Complex(){
            this->m_x = 0;
            this->m_y = 0;
        }
        Complex(double x, double y){
            this->m_x = x;
            this->m_y = y;
        }

        // 2.
        Complex operator+(Complex& another){
            Complex temp(this->m_x + another.m_x, this->m_y + another.m_y);
            return temp;
        }
        Complex operator-(Complex& another){
            Complex temp(this->m_x - another.m_x, this->m_y - another.m_y);
            return temp;
        }
        void printComplex(){
            cout << "( " << this->m_x << " + (" << this->m_y << "i)" << ")" << endl;
        }
    private:
        double m_x;
        double m_y;
};

// 1. 
// Complex operator+(Complex& c1, Complex& c2){
//     Complex temp(c1.m_x + c2.m_x, c1.m_y + c2.m_y);
//     return temp;
// }

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Complex c1(10, 20);
    Complex c2(2, 30);

    Complex c3 = c1 + c2;

    c3.printComplex();
    Complex c4 = c1 - c2 - c1; // 前面 c1-c2 返回的是一个匿名对象的值，该匿名对象再去减后面的 c1

    c4.printComplex();
}