#include <iostream>

/*
    运算符操作重载：
        实现双目运算符的重载

        1. += , -=
        2. 单目运算符号 ++a, a++
*/

using namespace std;
class Complex{
    // 1
    // friend void operator+=(Complex& c1, Complex &c2);
    // friend Complex& operator-=(Complex& c1, Complex& c2);
    // friend Complex& operator++(Complex&c1);
    // friend const Complex operator++(Complex& c1, int); // 不能使用引用因为传递的是局部变量的值

    public:
        Complex(){
            m_r = 0;
            m_i = 0;
        }
        Complex(double r, double i){
            m_r = r;
            m_i = i;
        }
        void printComplex(){
            cout << "(" << m_r << " + (" << m_i << "i)" << endl;
        }
        // void operator+=(Complex& another){
        //     this->m_i += another.m_i;
        //     this->m_r += another.m_r;
        // }
        // 实现连加等操作
        Complex& operator+=(Complex& another){
            this->m_i += another.m_i;
            this->m_r += another.m_r;
            return *this;
        }
        Complex& operator-=(Complex& another){
            this->m_i -= another.m_i;
            this->m_r -= another.m_r;

            return *this;
        }
        Complex& operator++(){
            this->m_i += 1;
            this->m_r += 1;
            
            return *this;
        }
        const Complex& operator++(int){ // 这个占位符被称为 亚元
            this->m_i += 1;
            this->m_r += 1;
            
            return *this;
        }
        Complex& operator--(){
            this->m_i--;
            this->m_r--;

            return *this;
        }
        const Complex operator--(int){
            Complex temp(this->m_r, this->m_i);

            this->m_r--;
            this->m_i--;

            return temp;
        }
    private:
        double m_r;
        double m_i;
};

// 1. 实现 +=
// void operator+=(Complex& c1, Complex& c2){
//     c1.m_r += c2.m_r;
//     c1.m_i += c2.m_i;
// }

// 实现 -=

// Complex& operator-=(Complex& c1, Complex& c2){
//     c1.m_r -= c2.m_r;
//     c1.m_i -= c2.m_i;

//     return c1;
// }

// 2. ++a
// Complex& operator++(Complex& c1){
//     c1.m_i += 1;
//     c1.m_r += 1;
//     return c1;
// }



// 实现 后加加操作运算符 a++, 这个不能进行连加，所以，在返回值面前加一个 const
// const Complex operator++(Complex& c1, int){
//     Complex temp(c1.m_r, c1.m_i);

//     c1.m_i++;
//     c1.m_r++;

//     return temp;
// }

// void printCom(const Complex c1){
//     c1.printComplex();
// }

void test01();

int main(void){
    test01();
    return 0;
}


void test01(){
    Complex c1(10, 20);
    Complex c2(40, 30);
    c1.printComplex();
    c2.printComplex();

    //1 
    // (c1+=c2)+=c2;
    // (c1-=c2)-=c2;
    // c1.printComplex();

    // 2.
    // ++++c1;
    // c1.printComplex();

    // printCom(c1++);
    // c1++++; // 因为 a++ 操作符号，本身就不能实现 多次 ++ ，所以这里操作符重载返回类型前面需要加一个const，防止改变原本的特性
    // c1++;
    c1--;
    c1.printComplex();
}