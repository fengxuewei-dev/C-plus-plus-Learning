#include <iostream>

using namespace std;

class AA{
    public:
        AA(){
            cout << "AA()" << endl;
        }
        AA(double x,double y):m_x(x), m_y(y){
            cout << "AA(double, double) begin" << endl;
            AA();   // 创建了一个匿名对象，该动作是危险的
            cout << "AA(double, double) end" << endl;
            /*
                test01 >>>>>> 
                AA(double, double) begin
                AA()
                ~AA()
                AA(double, double) end
                mid
                test01 <<<<<<
                ~AA()
            */
        }
        ~AA(){
            cout << "~AA()" << endl;
        }
    private:
        double m_x;
        double m_y;
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    cout << "test01 >>>>>> " << endl;
    // AA();  // 这是一个匿名对象，因为没有名字，在定义了之后，里面就会被释放，因此先调用构造函数，之后立马调用析构函数
    AA a1(1,2);
    cout << "mid" << endl;
    cout << "test01 <<<<<<" << endl;
}