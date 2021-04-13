#include <iostream>
#include <cstring>

/*
    初始化列表调用的 是 子对象的构造函数（构造函数 、拷贝构造函数）

    初始化列表先初始化（初始化顺序和初始化列表的先后顺序没有关系），之后执行构造函数的语句体

    析构和构造是一个出栈和入栈操作。

    当一个类中，成员变量中存在 常量，常量的定义的是在声明的时候一定要进行初始化，同时一经定义不可以修改
        类中数据成员内存空间的开辟，只有当创建该对象的时候，才会创建空间
        但是对于常量的赋值不能写到语句体内部，因为这样的话就是对常量进行修改，因此我们只能将常量写在初始化列表中.

    初始化列表：
    1. 什么数据必须放在初始化列表中进行初始化：
        1.1 类内包含其他数据类型的对象，在定义该类的时候，需要为其内部的数据成员进行初始化，分配内存
        1.2 类内包含 const 类型的数据成员，在定义对象的时候，在初始化列表中进行赋值和创建。总的来说，初始化列表就是定义类中的对象变量、和静态变量
    2、初始化的先后顺序
        2.1 初始化的先后顺序和该对象在类中定义的先后顺序有关，和初始化列表的和形参列表的先后顺序无关
    3、初始化的时候调用什么函数
        3.1 当该类中的成员对象，是以对象的形式传递进来的，调用的是拷贝构造函数
        3.2 当该类中的成员对象，是以对象内部的各个数据的形式传递进行来的，那么调用的是对应的构造函数。
    
*/

using namespace std;
class Teacher{
    public:
        Teacher():m_age(10){
            m_id = 0;
            m_name = NULL;

        }
        Teacher(int id, const char *name, const int age):m_age(age){
            
            cout << "Teacher(int , char): " << id<< endl;
            m_id = id;
 
            int len = strlen(name);
            m_name = (char*)malloc(sizeof(char) *(len + 1));
            strcpy(m_name, name);
        }

        Teacher(const Teacher& another):m_age(another.m_age){ // 深拷贝动作
            cout << "Teacher(const Teacher& another)" << endl;
            m_id = another.m_id;
            int len = strlen(m_name);
            m_name = (char*)malloc(sizeof(char)*(len+1));
            strcpy(m_name, another.m_name);
        }
        ~Teacher(){
            cout << "~Teacher" << endl;
            if(m_name != NULL){
                free(m_name);
                m_name = NULL;
            }

        }
        void print(){
            cout << "teacher's id = " << m_id << ", teacher's name = " << m_name <<", teacher's age = " << m_age << endl;
        }
    private:
        double m_id;
        char *m_name;
        const int m_age;
};
class Student{
    public:
        /*
            当一个类中有另外一个类的对象的时候，在为该对象进行初始化的时候，应该使用的构造函数初始化列表
            那么这两个 tea1 和 tea2 是如何进行初始化的呢？初始化顺序是什么样子的呢？
                类的构造成员的顺序和初始化列表的先后顺序无关；和对象的定义顺序有关系
        */
       // 调用 Teacher 类的拷贝构造函数
        Student(int id, const char *name, const Teacher & tea1, const Teacher & tea2):Tea1(tea1), Tea2(tea2){ // 后面会默认调用 Teacher Tea1的构造函数
            m_id = id;
            m_name = new char[strlen(name) + 1];
            if(m_name != NULL){
                strcpy(m_name, name);
            }
        }

        // 调用 teacher 类的有参数构造函数
        Student(int id, const char*name, int tea1_id, const char*tea1_name, const int tea1_age, int tea2_id, const char *tea2_name, const int tea2_age):Tea1(tea1_id, tea1_name, tea1_age), Tea2(tea2_id, tea2_name, tea2_age),m_id(id){
            m_name = new char[strlen(name) + 1];
            if(m_name != NULL){
                strcpy(m_name, name);
            }
        }
        ~Student(){
            cout << "~Student..." << endl;
            if(m_name != NULL){
                delete m_name;
                m_name = NULL;
            }
        }
        void printStu(){
            cout << "Name : " << m_name <<"\nid = " << m_id << endl;
            cout << "the information of his teacher:\n";
            Tea1.print();
            Tea2.print();
        }
    private:
        int m_id;
        char *m_name;
        Teacher Tea2;
        Teacher Tea1;
};

void test01(){
    Teacher t1(201500879, (char*)"zhangsan", 24);
    Teacher t2(201500880, (char*)"wangwu", 56);
    Student stu(201500927, (char*)"lisi", t1, t2);  // 调用 teacher 的拷贝构造函数
    // Student stu(201500927, (char*)"lisi", 201500879, (char*)"zhangsan", 201500880, (char*)"wangwu");
    t1.print();
    t2.print();
    stu.printStu();
}
void test02(){
    // Teacher t1(201500879, (char*)"zhangsan");
    // Teacher t2(201500880, (char*)"wangwu");
    // Student stu(201500927, (char*)"lisi", t1, t2);  // 调用 teacher 的拷贝构造函数
    Student stu(201500927, (char*)"lisi", 201500879, (char*)"zhangsan", 24, 201500880, (char*)"wangwu", 56);
    // t1.print();
    // t2.print();
    stu.printStu();
    /*
        Teacher(int , char)
        Teacher(int , char)
        Name : lisi
        id = 201500927
        the information of his teacher:
        teacher's id = 2.01501e+08, teacher's name = zhangsan
        teacher's id = 2.01501e+08, teacher's name = wangwu
        ~Student...
        ~Teacher
        ~Teacher
    */
}
int main(void){
    test02();
    return 0;
}