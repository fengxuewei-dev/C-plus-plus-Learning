#include <iostream>
// #include <cstring> // 和 string.h 一样 针对于 c
#include <string> // c++

using namespace std;


/*
    高内聚、低耦合、冗余度
    类中有三种关系：
        1. B has A ==> 包含，调用传递的参数
        2. C use A
        3. D is A ==> 继承（具有非常高的耦合性）
    
    可重用性：已经做好的工作不需要再去重复做，只需要添加额外的代码即可
    基类---派生类
    父类---子类

    单个类中的成员访问控制权限：
        public：类中的成员函数和类的外部都可以进行访问
        protected: 类中的成员函数可以访问，但是类的外部函数不能进行访问
        private： 类中的成员函数可以访问，但是类的外部函数是不能进行访问的
    
    类的继承方式：
        public: 这里的public和单类中的public不是一个意思，和 void 与 void* 一样
            父类 public 成员    ----    子类中的权限为 public       子类是可以访问到的；类外部也可以访问到
            父类 protected 成员 ----    子类中的权限是 protected    子类可以访问到，类外部是不可以访问到
            父类 private 成员   ----    子类中的权限是 不可见的
        private:
            父类 public 成员    ----    子类中的权限为 private       子类是可以访问到的；类外部不可以访问到
            父类 protected 成员 ----    子类中的权限是 private       子类可以访问到，类外部是不可以访问到
            父类 private 成员   ----    子类中的权限是 不可见的
        protected:
            父类 public 成员    ----    子类中的权限为 protected    子类是可以访问到的；类外部不可以访问到
            父类 protected 成员 ----    子类中的权限是 protected    子类可以访问到，类外部是不可以访问到
            父类 private 成员   ----    子类中的权限是 不可见的

    确定一个变量是否的访问权限是什么样子的？ 三看原则
        1. 该成员变量在调用的时候，是在类的内部还是外部
        2. 看派生类的继承方式
        3. 当前变量在 基类 中的访问控制权限
    
    一般继承的时候，都是采用公有继承，因为其他两种的继承方式比较复杂
*/

class Student{
    friend ostream& operator<<(ostream& os, const Student& st1);
    public:
        Student(int id, string name){
            this->id = id;
            this->name = name;
        }

        
        void printS(){
            cout << "id = " << id << "\t name = " << this->name;
        }
    private: // 私有成员在公有继承之后，派生类没有办法访问到
        int id; 
        string name;
};

ostream& operator<<(ostream& os, const Student& st1){
    os << "id = " << st1.id << "\t name = " << st1.name;
    return os;
}


class Student2:public Student{
    friend ostream& operator<<(ostream& os, const Student2& st2);
    public:
        Student2(int id, string name, double score):Student(id, name){ // 这个时候若不写后面 :Student(id, name) ；编译器会自动调用父类的默认无参构造函数，此时如果父类中缺少默认无参构造函数，则会报错
            this->score = score;
        }
        void printS(){
            Student::printS();
            cout << "\t score  = " << score << endl;
        }
    private:
        double score;
};
// ostream& operator<<(ostream& os, const Student2& st2){
//     os <<  << "\t score = " << st2.score << endl;
// }

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Student2 st1(10, "zhangsan", 80.0);

    st1.printS();
}