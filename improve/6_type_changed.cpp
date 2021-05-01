#include <iostream>

/*
    一般情况下，我们不建议进行类型转换
    
    类型转换： 我们需要考虑的是 在类型转换之前是什么样子的，在转换之后是什么样子的问题

    C语言强制类型转换： Type b = (Type)a;   // 无脑且强制 

    C++ 在做类型的转换，需要先做一个类型的检查，安全性相对于 C 语言要高

        static_cast 做一般的类型转换：基础的数据类型进行转换；指针以及引用（必须要有一定的继承关系，在一个继承树下）之间的相互转换

        dynamic_cast 主要在是基类和派生类之间的类型转换的使用（子类和父类之间的类型转换）转换的时候进行安全检查

        const_cast 指针、引用、对象指针， 增加/去除 const 引用

        reinterpret_cast 用于对任何数据类型进行转换，不要求他们有一定的特殊关系 

        static_cast:        内置数据类型；一个继承树下的指针或引用
        dynamic_cast:       基类和派生类
        const_cast:         指针、引用、对象指针 来增加或者去除const引用
        reinterpret_cast：  任何数据的类型
*/

// 函数指针是一个指针类型 使用的时候需要定义其对象
typedef int(*FUNC_INT)(int, int);
typedef char(*FUNC_CHAR)(char, char);

using namespace std;

void test01();
void test02();
void test03();
void test04();

int main(void){
    test03();
    return 0;
}

class Person{};
class Animal{};
class Cat : public Animal{};

void test04(){
    // reinterpret_cast 强制的类型转换 任何类型指针都可以转换为其他类型的指针，包括函数指针

    Person *p = NULL;
    Animal *ani = reinterpret_cast<Animal*>(p);


    Cat * cat = reinterpret_cast<Cat*>(p);


    // 函数指针类型的转换
    FUNC_INT fun_int;
    FUNC_CHAR fun_char= reinterpret_cast<FUNC_CHAR>(fun_int);
}
void test03(){
    /*
        const_cast: 指针、引用、对象指针
    */
    const int &a = 10;      // 这是一个 const int& 类型，后面的值是不可以进行修改的。
    int &c = const_cast<int&>(a);       // 去掉const作用之后，当我们修改c的值， 对应a的值也进行了修改

    c = 20;
    const int &d = const_cast<const int&>(c); // 加上 const 作用  d 是 c 的引用； 修改c的数据，d的数据也会进行修改
    // d = 30;
    c = 30;
    cout << a << " " << c << " " << d << endl;


    // 指针
    int* p = NULL;
    const int* pc = const_cast<const int*>(p);     
}

void test02(){
    /*
        dynamic_cast：转换具有继承关系的指针或者引用，但是指针局限于 子类转换为父类（大的转为小的）

        static_cast: 继承关系的指针相互进行转换；子类转换为父类；父类转换为子类都可以
    */

    // 1、dynamic_cast 转换具有继承关系的指针或者引用， 在转换之前会进行对象类型的检查

    // 基本数据类型的转换 不行
    // int a = 10;
    // char c = dynamic_cast<char>(a); // the type in a dynamic_cast must be a pointer or reference to a complete class type, or void *

    // 非继承关系的指针或者引用 不行
    // Person *p1 = NULL;
    // Animal *ani = dynamic_cast<Person*>(p1); // a value of type "Person *" cannot be used to initialize an entity of type "Animal *"

    // 继承关系的指针或引用
    // Animal *ani1 = NULL;
    // Cat *cat1 = dynamic_cast<Cat*>(ani1); // the operand of a runtime dynamic_cast must have a polymorphic class type 运行时dynamic_cast的操作数必须具有多态类类型 
    // 原因在于 dynamic_cast 在进行类型转换的时候会  进行 安全性检查

    // 继承关系转换：可以理解为一个大箱子和小箱子之间的类型转换；当使用一个子类指针转换到父类的指针，相当于一个大的箱子转换到 小的箱子 是可以进行的，但是当一个父类指针转换到一个子类指针，相当于一个小的箱子转换到大的箱子上面，此时指针会出现调用数据失败的情况，也就是该指针不能完全指向所有的内部数据，所以编译器在进行安全性检查出错 
    // ----------- 只能进行 子类指针转换为父类指针 ----------
    Cat *cat1 =  NULL;
    Animal *ani1 =dynamic_cast<Animal*>(cat1); 

    // 转换关系：原类型的指针转换为新类型的指针，指针能访问的空间只能缩小或者不变，不能进行扩大...

}

void test01(){
    /*
        static_cast： 只能转换内置数据类型的非指针或者引用类型的对象；转换具有继承关系的指针或引用
    */
    // 1、static_cast 内置数据类型
    int a = 97;         // 65 - 90： 大写字母； 97 - 122 ： 小写字母
    char c = static_cast<char>(a);      // 将a的类型转换为char类型
    cout << c << endl;

    // 2.1、基类指针或者引用 不能进行类型转换
    // int *pi = NULL;
    // char *pc = static_cast<char*> (pi); // invalid type conversion

    // 2.2、static_cast 没有继承关系的指针
    // Person *p = NULL;
    // Animal *a = static_cast<Animal*>(p);   // invalid type conversion

    // 3、static_cast 具有继承关系的指针或引用，父类转换为子类；子类转换为父类 都是可以的
    Cat *cat = NULL;
    Animal *ani = static_cast<Animal*>(cat);

    Animal *ani1 = NULL;
    cat = static_cast<Cat*>(ani1);

    Cat cat1;
    Animal& ani2 = static_cast<Animal&>(cat1);

    Animal ani3;
    Cat& cat2 = static_cast<Cat&>(ani3);
}