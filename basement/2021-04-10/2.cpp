#include <iostream>

using namespace std;


class Test{
    public:
        Test(){
            m_x = 0;
            m_y = 0;
            cout << "Test()" << endl;
        }
        Test(double x, double y){
            m_x = x;
            m_y = y;
            cout <<"Test(double, double)" << endl;
        }

        ~Test(){
            cout << "~Test()" << endl;
        }

        Test(const Test& another){
            cout << "Test(const Test& another)" << endl;
        }

        void operator=(const Test& another){
            m_x = another.m_x;
            m_y = another.m_y;
            cout << "operator=(const Test& another)" << endl;
        }
        void printXY(){
            cout << "m_x = " << m_x <<"， m_y = " << m_y << endl;
        }
    private:
        double m_x;
        double m_y;
};

Test func(){
    cout << "func begin..." <<endl;
    Test t1(20,30);
    t1.printXY();
    cout << "func end..." <<endl;
    return t1;
} 

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    
    cout << "Test01 begin..." <<endl;
    Test t1 = func(); // 这里也没有发生默认拷贝构造函数的调用
    t1.printXY();
    Test t2 = t1;
    cout << "Test01 end..." <<endl;
}