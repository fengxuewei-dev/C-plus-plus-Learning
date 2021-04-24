#include <iostream>

using namespace std;

/*
    VTPR 指针是分步初始化；所以一般在写代码的时候，不要在构造器中执行某个业务

    多态的实现原理：VTPR 指针， 虚函数表（所属于对象本身内部） ==> 通过sizeof来验证

    VPTR 指针，在创建子类对象调用对应的构造函数的过程中，先创建子类中继承父类的那部分空间，此时 产生的 VTPR 指针会临死指向父类的虚函数表，
    
    当 调用完父类构造函数之后，内存空间重新作为子类的内存空间进行处理，vtpr指针就重新指向子类的虚函数表


    不可以使用父类指针来遍历子类对象... 当子类中有新定义的数据类型的时候，使用父类指针的时候，指针++ 加的是 父类的字节数的大小，当父类字节数 < 子类字节数的时候，就会发生崩溃 ===> 指针的++ 并没有多态性
*/

class Parents{
    public:
        Parents(int a){
            cout << "Parent(int)..." << endl;
            this->a = a;
        }
        virtual void print(){
            cout << "Parent::print()..." << "a = " << a << endl;
        }
        int a;
};

class Child : public Parents{
    public:
        Child(int a, int b) : Parents(a){
            cout << "Child(int)..." << endl;
            this->b = b;
        }
        virtual void print(){
            cout << "Child::print()..." << "a = " << a << " b = " << b << endl;
        }
        int b;
    private:
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Child **cpp = new Child*;

    for(size_t i = 0; i < 4; i++){
        cpp[i] = new Child(i, i);
    }

    for(size_t i = 0; i < 4; i++){
        cout << "cpp[" << i << "] = "; cpp[i]->print();
    }

    cout << "-----------------" << endl;
    Parents **ppp = new Parents*;
    for(size_t i = 0; i < 4; i++){
        ppp[i] = cpp[i];
    }

    for(size_t i = 0; i < 4; ppp++){
        cout << "cpp[" << i << "] = "; (*ppp)->print();
    }
}