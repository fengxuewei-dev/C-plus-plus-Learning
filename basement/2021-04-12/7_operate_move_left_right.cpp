#include <iostream>


/*
    左移 和 右移 操作符号的重载
    cout << 
    cin >> 
*/
using namespace std;
class Complex{
    // 1
    // friend void operator+=(Complex& c1, Complex &c2);
    // friend Complex& operator-=(Complex& c1, Complex& c2);
    // friend Complex& operator++(Complex&c1);
    // friend const Complex operator++(Complex& c1, int); // 不能使用引用因为传递的是局部变量的值
    friend istream& operator>>(istream &in, Complex& c1);
    friend ostream& operator<<(ostream &out, Complex &c1);
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
        // c++ 中 左运算符 不介意写在类中，因为会改变原来的使用特性.
        // ostream& operator<<(ostream out){
        //     out << "(" << this->m_r << " + (" << this->m_i << "i))";
        //     return out;
        // } // 调用方式需要 c1.operator(cout); ==> c1 << cout 这种方法是可以执行成功的，但是改变了原来的使用特性。

    private:
        double m_r;
        double m_i;
};
// 下面是全局形式的
// 假设我们需要将其转变为全员的形式，
ostream& operator<<(ostream &out, Complex &c1){
    out << "(" << c1.m_r << " + (" << c1.m_i << "i))";
    return out;
}

istream& operator>>(istream &in, Complex& c1){
    in >> c1.m_r >> c1.m_i;

    return in;
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3;
    cout << c1 << "\n" << c2 << endl;

    cin >> c3 >> c3;
    // c3.printComplex();
    cout << c3 << endl;
    // cout << a << a << a << endl; // 需要返回 ostream 类型的对象
}
