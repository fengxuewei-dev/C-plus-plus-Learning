#include <iostream>
#include <memory>

/*
    智能指针：在STL中存在一个，模版对象来实现智能指针的功能：
    智能指针：在new之后，不需要手动去释放该块内存空间，系统会自动进行回收 
            需要的头文件的是 #include <memory>
            智能指针为 auto_ptr<int> ==> int *
*/

using namespace std;

class Test{
    public:
        Test(){
            this->m_x = 0;
        }
        ~Test(){
            cout << "~Test()... " << endl;
        }
        double getX(){
            return this->m_x;
        }
    private:
        double m_x;
};

class MyAutoPtr{
    public:
        MyAutoPtr(void *ptr){
            this->ptr = ptr;
        }
        ~MyAutoPtr(){
            if(this->ptr != NULL){
                delete this->ptr;
                this->ptr = NULL;
            }
        }
        void* getPtr(){
            return this->ptr;
        }

        void* operator->(){
            return  this->ptr;
        }
        void* operator*(){
            return  this->ptr;
        }
    private:
        void *ptr;
        
};

void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test01(){
    // int *p = new int;
    // *p = 20;
    // delte p;
    auto_ptr<int> p(new int);   // 创建一个智能指针，传递的形参是 字节个数，new int
    *p = 20; // 不需要delete
}
void test02(){
    auto_ptr<Test> t1(new Test);

    t1->getX();
}
void test03(){
    MyAutoPtr ptr(new Test);

    Test *value = (Test *)ptr.getPtr();

    cout << value->getX()  << endl; 
    // 这里 是因为 是 void * 类型，是一个万能指针不需要对其进行delete释放内存! 可以将形参中的void * 类型修改为特定类型
    // 这也就是为什么 auto_ptr<> 智能指针需要一个传递数据类型的 模版

    // ((Test*)ptr->)getX();
}
