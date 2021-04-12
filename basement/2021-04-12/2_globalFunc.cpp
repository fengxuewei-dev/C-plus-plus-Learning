#include <iostream>

using namespace std;


// 实现两个同名类的相加
class Test{
    public:
        Test(){

        }
        Test(double x, double y){
            this->m_x = x;
            this->m_y = y;
        }
        double getX(){
            return this->m_x;
        }
        double getY(){
            return this->m_y;
        }
        void printXY(){
            cout << "x = " << m_x << " , y = " << m_y << endl;
        }
        Test TestAdd1(const Test t1){
            Test temp(this->m_x + t1.m_x, this->m_y + t1.m_y);
            return temp;
        }
        void TestAdd2(const Test t1){
            // t1.m_x = 20;
            this->m_x += t1.m_x;
            this->m_y += t1.m_y;
        }
        Test& TestAdd3(const Test t1){
            this->m_x += t1.m_x;
            this->m_y += t1.m_y;

            return *this;
        }
        // Test* TestAdd3(const Test t1){
        //     this->m_x += t1.m_x;
        //     this->m_y += t1.m_y;

        //     return this;
        // }
    private:
        double m_x;
        double m_y;
};

Test TestAdd(Test& t1, Test& t2){ // const Test *const t1, 不能修改地址不能进行修改值.
    Test t3(t1.getX() +t2.getX(), t1.getY() +t2.getY());
    return t3;
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Test t1(20, 30);
    Test t2(30, 40);
    // 1.
    // Test t3 = TestAdd(t1, t2);  // 匿名对象转正赋值给t3，之后该匿名对象进行释放

    // 2.
    // Test t3 = t1.TestAdd1(t2);
    

    t1.printXY();
    // 3. 对调用 该函数的对象内部数据进行修改
    // t1.TestAdd1(t2);

    // 4. 连续加操作 如果想对一个对象来调用该对象的相同成员函数，那么使用返回this引用即可
    // t1.TestAdd3(t2)->TestAdd3(t2)->TestAdd3(t2);
    t1.TestAdd3(t2).TestAdd3(t2).TestAdd3(t2);

    t1.printXY();
}