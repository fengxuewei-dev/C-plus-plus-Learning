#include <iostream>

using namespace std;

// 下面的编译问题

/*
    编译器在链接的时候，会根据函数符号来寻找对应的函数实现，找到之后，就会链接上；找不到就链接失败了，就报无法解析的外部符号

    类模版在外部实现，不要随便使用友元函数
*/

template<class T>
class Person{
    
    // 下面的写法在 window 下面的 visual stdio 上面是可以编译通过的 但是在linux下面是不能通过，这个是编译器差异导致的这个问题
    /*
    template<class T>
    // friend ostream & operator<<(ostream & os, Person<T>& p);
    */ 

    // friend ostream& operator<< <T>(ostream & os, Person<T>& p);


    template<class T>
    friend void print(Person<T> *p);

    public:
        Person(T age, T id);
        T getId();
        T getAge();
        void Show();
    private:
        T mId;
        T mAge;
};

template<class T>
Person<T>::Person(T age, T id){
    this->mAge = age;
    this->mId = id;
}

template<class T>
void Person<T>::Show(){
    cout << "id = " << this->mId << " age = " << this->mAge << endl;
}

template<class T>
T Person<T>::getId(){
    return this->mId;
}
template<class T>
T Person<T>::getAge(){
    return this->mAge;
}

// 操作符重载：是一个普通的函数，而下面的这个是一个 函数模版，二者不是一个概念
/*
 template<class T>
// ostream& operator<< <T>(ostream & os, Person<T>& p){
//     os << p.mId << "'s age = " << p.mAge;
//     return os;
// }
*/

template<class T>
void print(Person<T> *p){
    cout << p->mAge << " " << p->mId << endl;
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Person<int> *p1 = new Person<int>(10, 20);

    // cout << p1 << endl;
    print(p1);

    delete p1;
}