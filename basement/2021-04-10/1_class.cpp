#include <iostream>
#include <cstring>

/*
    在显式的给定一个有参构造函数的时候，默认无参构造函数就被隐藏了
    \
    构造函数是可以重载的，但是析构函数不支持重载

    拷贝构造函数：
        当想要使用一个类型的对象为另外一个该类型的对象来赋值的时候，就要定义拷贝构造函数
*/

using namespace std;

class Test{
    public:
        Test(){
            cout << "Test()" << endl;
            m_x = 0;
            m_y = 0;
        }
        Test(int x, int y){
            cout << "Test(int ,int)" << endl;
            m_x = x;
            m_y = y;
            name = (char*)malloc(sizeof(char)*64);
            strcpy(name, "helloworld");
        }
        ~Test(){
            cout << "调用析构函数！" << endl;
            if(name != NULL){
                cout << "释放name的空间！" << endl;
                free(name);
                name = NULL;
            }
        }
        Test(const Test& another){
            cout <<" Test(const Test& another): " << endl;
            m_x = another.m_x;
            m_y = another.m_y;
            name = another.name;
            // 操作系统对对象进行回收之前
        }

        char * getName(){
            return name;
        }
        void printXY(){
            cout << "X = " << m_x << " , Y = " << m_y << endl;
        }
        void operator=(const Test& another){
            cout <<" Test operator>: " << endl;
            m_x = another.m_x;
            m_y = another.m_y;
            name = another.name;
        }
    private:
        int m_x;
        int m_y;
        char *name;
};
void test01();
void test02();
void test03();
void test04();

void func(Test t1){
    cout << "func begin..." << endl;
    t1.printXY();
    cout << "func end..." << endl;
}
Test func2(){
    cout << "func2 begin..." << endl;
    Test t(89,90);
    t.printXY();
    cout << "func2 end..." << endl;
    return t;
} 
//1. 返回的时候会执行一个： 匿名的对象 = t; 调用拷贝构造函数
//2. 调用析构函数，将局部变量 t 进行释放


int main(void){
    test04();
    return 0;
}

void test01(){
    // Test t1; // 会出错 no matching function for call to ‘Test::Test()’
    Test t1(10,20);
    t1.printXY();
    cout << "T1.name = " << t1.getName() << endl;

    Test t2(t1); // 调用拷贝构造函数
    t2.printXY();
    cout << "T2.name = " << t2.getName() << endl;


    // Test t3 = t1;// 调用 t3 的拷贝构造函数
    /*
        Test t3;
        t3 = t1;    // 默认拷贝构造函数是在初始化的时候进行调用的，在这一步 t3 已经初始化完成。这一步执行的是赋值操作符函数
        void operator=(const Test& another){
    */
   Test t3;
   t3 = t1;
   t3.printXY();

   /*
        构造函数：默认构造函数 & 默认拷贝构造函数
        析构函数：默认析构函数
        操作符号重载：
   */
}

void test02(){
    cout << "test02() begin...." << endl;
    Test t1(10,20);
    func(t1);
    cout << "test02() end...." << endl;
}

void test03(){
    cout << "test03() begin...." << endl;
    func2();
    cout << "test03() end...." << endl;
}

void test04(){
    cout << "test04() begin...." << endl;
    Test t1 = func2();  // 在 func2() 函数中返回值的时候，有一个匿名对象 = return的对象，调用拷贝构造函数，这个时候，fun2() 就是该匿名对象，这里不会再一次进行拷贝函数处理了，因为没有意义，所以这里主要是将 该匿名对象进行转正.
    cout << "test04() end...." << endl;

}