#include <iostream>

using namespace std;

/*
    类模版:
        将内部使用到的类型进行模版化

        函数模版在调用的时候，可以自动类型推导；类模版在调用的时候，必须显式指定类型
*/

template<class T> // template<typename T>
class tempClass{
    public:
        tempClass(T id, T mAge){
            this->id = id;
            this->mAge = mAge;
        }

        virtual void Show(){
            cout << "id = " << id << endl;
            cout << "mAge = " << mAge << endl;
        }
    private:
        T id;
        T mAge;
};

template<class T>
class tempClassChild : public tempClass<T>{
    public:
        tempClassChild(T id, T age) : tempClass<T>(id, age){
            this->m_child_age = age;
            this->m_child_id = id;
        }

        virtual void Show(){
            cout << "id = " << m_child_id << endl;
            cout << "age = " << m_child_age << endl;
        }

    private:
        T m_child_id;
        T m_child_age;
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){

    tempClass<int> *temp1 = new tempClassChild<int>(20 ,20);

    temp1->Show();

    delete temp1;
}