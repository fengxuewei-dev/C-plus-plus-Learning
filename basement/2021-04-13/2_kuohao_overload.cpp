#include <iostream>

using namespace std;


/*
    重载小括号：仿函数

    重载 new 和 delete
*/

class power{
    public:
        power(){
            cout <<"power()..." << endl;
        }
        power(double a){
            cout <<"power(double)..." << endl;
            this->m_a = a;
        }
        ~power(){
            cout << "~power()... " << endl;
        }
        double operator()(double value1, double value2){
            return value1 * value2;
        }

        // 虽然重载了new关键字，但是使用new来创建对象的时候，调用完重载的函数体之后，再去调用 对应的构造函数
        // 一般不对new进行重载。可以在函数体内部做一些个日志记录功能。
        void* operator new(size_t size){
            cout << "overload operator new..." << endl;
            return malloc(size);
        }
        void* operator new[](size_t size){
            cout << "overload operator new[]..." << endl;
            return malloc(size);
        }
        // delete 重载：先调用析构函数，再调用重载函数体
        void operator delete(void * ptr){
            cout << "operator delete ..." << endl;
            free(ptr);
            ptr = NULL;
        }
        void operator delete[](void * ptr){
            cout << "operator delete[] ..." << endl;
            free(ptr);
            ptr = NULL;
        }

    private:
        double m_a;
};

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test01(){
    power *p = new power(20);    // 这里的 20 是因为 new 会触发 构造函数，之后进行触发。
    // p->operator new(sizeof(A));

    cout << p->operator()(20, 39) << endl;

    if(p != NULL){
        delete p;
        p = NULL;
    }
}
void test02(){
    power *p = new power[10]; // 开辟了10个空间

    // p->operator new[](sizeof(power) * 20);
    if(p != NULL){
        delete[] p; // 释放了10个空间
        p = NULL;
    }
}