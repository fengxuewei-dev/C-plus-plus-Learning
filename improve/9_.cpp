#include <iostream>
#include <cstring>

using namespace std;

/*
    为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有类型
*/

// 这个函数只能抛出 int float char 三种类型的异常, 当抛出其他类型的异常，程序就会报错
void func() throw(int, float, char){
    throw "xxx";
    // terminate called after throwing an instance of 'char const*'
    // Aborted (core dumped)
}

void func2() throw(){
    // 不能抛出任何异常
    throw "ccc";
}

// 可以抛出任何类型的异常
void func3(){

}


class MyException{
    public:
        MyException(const char *const error){
            cout << "MyException(const char *const error);" << endl;
            this->mError = new char[strlen(error) + 1];
            strcpy(this->mError, error);
        }
        ~MyException(){
            cout << "~MyException()" << endl;
            if(this->mError != NULL){
                delete[] this->mError;
                this->mError = NULL;
            }
        }
        MyException(const MyException& another){
            cout << "MyException(const MyException& another);" << endl;
            if (&another == this)
            {
                return;
            }
            this->mError = new char[strlen(another.mError) + 1];
            strcpy(this->mError, another.mError);
            
        }

        // 等号运算符重载需要返回的是 引用
        MyException& operator=(const MyException& another){
            cout << "MyException& operator=(const MyException& another);" << endl;
            if (&another == this)
            {
                return *this;
            }

            if(this->mError != NULL){
                delete[] this->mError;
                this->mError = NULL;
            }

            this->mError = new char[strlen(another.mError) + 1];
            strcpy(this->mError, another.mError);

            return *this;
        }

        void what(){
            cout << this->mError << endl;
        }
    private:
        char *mError;
};

// 异常类型可以是数字、字符串、类对象
void func4(){
    // throw 1;
    // throw "aaa"; // const char 
    MyException p1(static_cast<const char *>("the function exception"));
    throw p1;
}

void func5(){
    // MyException p1(static_cast<const char *>("the function exception"));
    // throw &p1;

    throw new MyException(static_cast<const char *>("the function exception"));
}

void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test03(){

    try{
        // func();
        // func2();
        func5();
    }catch(const char * e){ // catch 需要严格匹配异常类型
        cout << e << endl;
    }catch(int e){
        cout << e << endl;
    }catch(float e){
        cout << e << endl;
    }catch(MyException* e){ // 指针，抛出异常的时候，使用指针进行接收，抛出异常的地址. 但是 这个时候传递的是 局部变量的引用， 在调用 下面的 what 函数之前就将该对象进行了释放. 没有达到抛出异常的目的。此时需要 new 一个对象，在使用完成之后，将其 delete掉。
        e->what();
        delete e;
    }catch(...){ // 捕获所有的异常 ...
        cout << "未知类型异常" << endl;
    }

    cout << "end" << endl;

    // MyException(const char *const error);
    // the function exception
    // ~MyException()
    // end


}
void test02(){
    try{
        // func();
        // func2();
        func4();
    }catch(const char * e){
        cout << e << endl;
    }catch(int e){
        cout << e << endl;
    }catch(float e){
        cout << e << endl;
    }catch(MyException& e){ // 这里会调用拷贝构造函数，因为程序没有显式定义拷贝构造函数，所以这里是浅拷贝。在调用析构函数的时候，会出现同时释放相同的内存空间... 引用的时候，不会调用构造函数，会调用拷贝构造函数，同样也不会进行析构函数的调用。异常处理完之后就会析构
        e.what();
    }catch(...){ // 捕获所有的异常 ...
        cout << "未知类型异常" << endl;
    }

    cout << "end" << endl;
    // MyException(const char *const error);
    // MyException(const MyException& another);
    // ~MyException()
    // the function exception
    // ~MyException()
    // end


}
void test01(){
    try{
        // func();
        // func2();
        func4();
    }catch(const char * e){
        cout << e << endl;
    }catch(int e){
        cout << e << endl;
    }catch(float e){
        cout << e << endl;
    }catch(MyException e){ // 这里会调用拷贝构造函数，因为程序没有显式定义拷贝构造函数，所以这里是浅拷贝。在调用析构函数的时候，会出现同时释放相同的内存空间
        e.what();
    }catch(...){ // 捕获所有的异常 ...
        cout << "未知类型异常" << endl;
    }

    cout << "end" << endl;
    // 异常的生命周期：
    // MyException(const char *const error);
    // MyException(const MyException& another);
    // ~MyException()
    // MyException(const MyException& another);
    // the function exception
    // ~MyException()
    // ~MyException()
    // end


    // 普通元素，在catch处理完成之后, 生命周期结束 执行析构

}