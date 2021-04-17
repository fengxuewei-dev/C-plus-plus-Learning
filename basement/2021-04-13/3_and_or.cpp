#include <iostream>

using namespace std;

class Test{
    public:
        Test(){

        }
        Test(double x){
            this->m_x = x;
        }

        ~Test(){
            cout << "~Test()..." << endl;
        }

        bool operator&&(const Test& t1){
            return this->m_x > 0 && t1.m_x > 0;
        }
        bool operator||(const Test& t1){
            return this->m_x > 0 || t1.m_x > 0;
        }
    private:
        double m_x;
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Test t1(20);
    Test t2(-10);
/*
    一般情况下：if(a && b) // 当 a 为假的时候，不执行 b，b 会进行所谓的短路；重载&& 会导致短路现象失效
    同理 || 也是一样的道理

    因为操作符重载，本质还是调用函数，先有一个传递产生的一个过程，此时，就会先执行后面的部分，再去执行该函数。
*/
    if(t1 && t2){
        cout << "false.. " <<endl;
    }else{
        cout << "true ..." << endl;
    }

    if(t1 || t2){
        cout << "false.. " <<endl;
    }else{
        cout << "true ..." << endl;
    }
}