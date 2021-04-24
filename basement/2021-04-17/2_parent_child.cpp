#include <iostream>

using namespace std;

/*
    子类内部包含的元素个数要比父类要多,内存空间要大，所以才出现了下面的若干条性质
    & 子类对象内部包含了一个父类对象

    兼容性赋值
        1. 子类的对象可以为父类对象赋值
        2. 子类的对象可以当做父类对象使用
        3. 子类对象是可以直接初始化父类对象

        4. ************ 父类指针可以直接指向子类对象 ************ ==> 使用一个接口可以包含所有家族成员

    

    子类的构造函数和析构 函数
    构造顺序：父类 --> 子类
    析构顺序：子类 --> 父类

    出现重名变量或者函数
*/

class Child;
class Parents{
    friend class Child;
    public:
        Parents(){
            cout << "Parents()...." << endl;
            this->a = 10;
        }
        Parents(int a){
            cout << "Parents(int)...." << endl;
            this->a = a;
        }
        ~Parents(){
            cout << "~Parents()...." << endl;
        }
        void Word(){
            cout << "Parents ---> Word().... " << endl;
        }   
        void run(){
            Word();
            cout << "Parents ---> Run()...." << endl;
        }
        int a;
};

class Child : public Parents{
    public:
        Child():Parents(){
            cout << "Child()...." << endl;
            this->b = 20;
        }
        Child(int c_a, int c_b, int p_a):Parents(p_a){
            this->a = c_a;
            this->b = c_b;
        }
        ~Child(){
            cout << "~Child()...." << endl;
        }
        void Word(){
            cout << "Child ---> Word().... " << endl;
            cout << Parents::a << endl;
            cout << this->a << endl;
        }

        void run(){
            Word();
            cout << "Child ---> Run()...." << endl;
        }

        int b;
        int a;
};

class Child2 : public Parents{
    public:
        Child2():Parents(20){
            cout << "Child2()...." << endl;
            this->c = 30;
            
        }
        ~Child2(){
            cout << "~Child2()...." << endl;
        }
        void Word(){
            cout << "Child2 ---> Word().... " << endl;
        }

        void run(){
            Word();
            cout << "Child2 ---> Run()...." << endl;
        }
        int c;

};

void MyPrint(Parents *pp){
    pp->Word();
}

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test02(){
    Child c1(10, 20, 30);
    c1.Word();
}


void test01(){
    Parents p1;
    Child c1;
    Child c2;

    // c1 = p1;
    // p1 = c1;

    Parents *pp = NULL;
    Child *pc = NULL;

    // 正常指向 
    // pp = &p1;
    // pc = &c1;

    // 

    pp = &c2;       // 父类指针指向子类对象
    // pc = &p1;       // 子类指针不能指向父类对象

    // pp->b
    pp->run();
    cout << pp->a << endl;

    MyPrint(&c1);
    MyPrint(&c2);
}