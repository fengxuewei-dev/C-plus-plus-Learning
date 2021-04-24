#include <iostream>

using namespace std;

/*
    父类中的static变量：在继承的时候，对整个家族都是共享的

    类中 static 变量是属于当前该类的，独立于对象来存在的。在类定义完成之后，在类外对其进行初始化
    static 成员函数用来访问 static 成员变量，也是独立于对象存在的。
*/

class Parents{
    public:
        Parents(){
            this->b = 20;
        }
        Parents(int b){
            this->b = b;
        }
        static int& getA(){
            return a;
        }
        static void addA(int b){
            a += b;
        }
        static int c;       // 可以被继承
    private:
        static int a;
        int b;
};
int Parents::a = 10;    // 在全局区进行开辟空间
int Parents::c = 100;

class B : public Parents{
public:
private:
};

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test02(){
    B b1;
    cout << B::c << endl;
    cout << &B::c << endl;
    cout << &Parents::c << endl;
}

void test01(){
    Parents p1(20);
    cout << p1.getA() << endl;
    p1.addA(10);
    Parents p2;
    cout << p2.getA() << endl;
    p2.addA(10);
    Parents p3;
    cout << p3.getA() << endl;

    cout << &p2.getA() << endl;
    cout << &p3.getA() << endl;
}