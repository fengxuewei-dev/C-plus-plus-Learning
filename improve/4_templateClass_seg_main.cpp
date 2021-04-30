#include <iostream>
#include "4_templateClass_seg.hpp"

using namespace std;

/*
    类模版的分文件来进行编写：

    编译器进行编译： 独立编译 -- 
        假设有多个源文件 .cpp 文件，编译器首先分文件进行独立编译，生成对应的.o文件之后，将其进行链接，生成可执行文件。但是在生成.o文件的时候，编译器不管程序内部的调用情况。

    当一个源文件进行编译的时候，发现有一个函数在调用的时候，函数实现体在该文件内部没有找到实现体，此时编译器编译该文件的时候在函数调用的位置生成一个函数符号，来标明该函数是在其他文件中进行定义的。等待链接的时候 让链接器寻找  函数实现体进行链接.

    函数模版在调用的时候会进行二次编译，第一次编译函数模版，第二次在调用函数的时候进行编译生成对应的模版函数
*/

/*
    这个项目中，存在三个文件:两个.cpp 文件，一个.hpp 文件。那么在编译 main.cpp 文件的时候，预处理阶段会将 .hpp 文件包含进来，此时编译到 test01 的时候，编译器找不到函数 show 的实现体，此时会在该函数调用的位置生成一个函数符号，等待链接器在链接的时候进行寻找.
    之后，编译器会编译另外一个cpp文件，也就是类模版的函数实现，相当于内部的实现的函数都是函数模版，编译器在第一次编译的时候，编译这些函数模版，之后等待调用的时候，再去二次编译这个函数模版生成对应的模版函数。
    此时在 main 函数中生成对对象的时候调用其构造方法，传入的模版类型是int类型，但是编译器并没有生成对应的模版函数生成， 生成对应的函数符号，等待编译器去寻找。此时后面的函数调用不会再次进行编译，该文件编译完成.
    
    此时编译类模版函数定义的具体文件，此时是函数模版，需要进行二次编译，但第二次编译的时候需要在调用的时候进行生成。此时并没有调用该文件内部的函数模版，因此第二次编译并没有进行，模版函数没有生成， 但该文件已经编译完成，生成了对应的.o文件。
    
    在链接的时候，链接器会将所有的是 .o 文件进行合并，链接器根据函数符号寻找函数实现体的时候 找不到，出现了 无法链接到外部符号的错误 
*/

// 解决方案：不包含 头文件，将 源文件包含进来，也就是包含 .cpp 文件
// 相当于把整个模版文件拷贝进来了，在编译器预处理的时候，会将这个头文件包含进来，之后对main文件进行编译，第一次的时候，会编译函数模版，第二次编译main方法的时候，会生成对应的模版函数进行调用.

// 一般在定义头文件的时候，将其命名为 .h，但是当定义类模版的时候，类的声明文件命名为.h文件，但是将其函数实现体文件命名为 .hpp ，这样我们在查看代码的时候就可以发现 .hpp 头文件就是 类模版的函数实现文件

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

// 类模版中的静态成员变量属于具体的类. 因为类模版不能进行实例化，所以当 static 属于类模版的时候，没有办法访问这个 数据空间。没有意义、
void test02(){
    Person<int> p(20);   
    p.a = 30; 
    p.show();
    cout << p.a << endl;
    Person<double> p1(390);

    p1.a = 40;
    cout << p.a << endl;
    cout << p1.a << endl;


}

void test01(){
    Person<int> p(20);    
    p.show();
}