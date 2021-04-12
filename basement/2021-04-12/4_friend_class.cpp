#include <iostream>

/*
    友元类:
        友元关系是单向传递的，不具有交换性。
        B是类A的友元，类A将类B作为朋友，但是类B不把类A作为朋友，也就是说在 类A 中不能访问类B中的私有数据成员
、
    关系之间不能传递
        单向
        友元关系不能被继承
        不能具有传递性
*/
using namespace std;

class A{
    friend class B;
    public:
        A(){

        }
        A(int x){
            this->m_x = x;
        }

        void printX(){
            cout << "x = " << m_x << endl;
        }
    private:
        int m_x;
};

class B{
    public:
        B(){

        }
        B(int y){
            this->m_y = y;
        }
        void printY(){
            A objA(320);
            // objA.printX();
            cout << objA.m_x << endl;  // 想要在对象 objA 中访问私有变量A的成员x
            cout << "y = " << m_y << endl;
        }
    private:
        double m_y;
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    B b(20);
    b.printY();
}