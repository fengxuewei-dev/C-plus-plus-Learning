#include <iostream>
using namespace std;
/*
    静态数组的实现：
        份文件编写的时候会出现错误...
*/

// 容量的概念
// 当前内部存放多少元素
// 数组保存数据的首地址
#define SIZE_MAX_H_ 100

template<class T>
class MyArray{
    public:
        MyArray(int capacity);

        ~MyArray();
        MyArray(const MyArray<T>& another); 

        T& operator[](int index){
            return this->pAddr[index];
        }

        MyArray operator=(const MyArray<T>& arr){
            if(this == *arr){
                return *this;
            }
            if(this->pAddr != NULL){
                delete[] this->pAddr;
                this->pAddr = NULL;
            }

            this->mCapacity = arr->mCapacity;
            this->mSize = arr->mSize;

            this->pAddr = new T[this->mCapacity];
            for(size_t i = 0; i < this->mSize; i++){
                this->pAddr[i] = arr->pAddr[i];
            }
            return *this;

        }

        void PushBack(T& value) // 在最后追加元素，当内存空间不足的时候，会失败，返回0
        {
            if(this->mCapacity <= this->mSize){
                return;
            }

            // 在这里我们存放的是基本数据类型，那么直接使用 等号 将其放入容器内部；这里可能会调用拷贝构造函数或者等号重载操作符
            // 1、对象元素必须能够被拷贝
            // 2、容器都是值寓意的，而非引用寓意 ==》也就是再往容器中存放数据，都是将数据进行了一份拷贝，将拷贝之后的数据存放在容器中 ==》存放元素的拷贝
            // 这里是将 value 进行拷贝了一份数据，将其放在数组中
            // 3、如果元素的成员内部存在指针的时候，存在一个深浅拷贝的问题
            this->pAddr[this->mSize++] = value;
        }


        // T&& 对右值进行取引用  =-》 多加了一个取地址
        void PushBack(T&& value) // 在最后追加元素，当内存空间不足的时候，会失败，返回0
        {
            if(this->mCapacity <= this->mSize){
                return;
            }
            this->pAddr[this->mSize++] = value;
        }
        int getSize(){
            return this->mSize;
        }

    private:
        int mCapacity;  // 容量
        int mSize;      // 存放多少元素
        T* pAddr;       // 数据元素的首地址

};

template<class T>
MyArray<T>::MyArray(int capacity){
    this->mCapacity = capacity;

    this->mSize = 0;

    this->pAddr = new T[this->mCapacity];    
}

template<class T>
MyArray<T>::~MyArray(){
    if(this->pAddr != NULL){
        delete[] this->pAddr;
        this->pAddr = NULL;
    }
    this->mCapacity = 0;
    this->mSize = 0;
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& another){
    if(*another == this){
        return;
    }
    
    this->mCapacity = another.mCapacity;
    this->mSize = another.mSize;
    this->pAddr = new T[this->mCapacity];

    for(size_t i = 0; i < another.mSize; i++){
        this->pAddr[i] = another.pAddr[i];
    }
}

class Person{

};

void test01();
void test02();

int main(void){
    test02();
    return 0;
}


void test02(){
    Person p1, p2;

    MyArray<Person> *arr = new MyArray<Person>(10);

    arr->PushBack(p1);
    arr->PushBack(p2); // 在为一个类对象进行赋值的时候，是通过等号进行赋值操作，那么该类中就需要存在拷贝构造或者等号操作符 ==> 那么就会存在一个深浅拷贝的问题

    for(size_t i = 0; i < arr->getSize(); i++){
        cout << (*arr)[i] << endl;
    }
}
void test01(){
    MyArray<int> *arr = new MyArray<int>(10);

    // for(int i = 0; i < 10; i++){
    //     arr->PushBack(i);// = i + 10;
    // }    

    // 不能对右值取引用...
    // 左值可以在多行被使用
    // 右值只能在当前行使用，一般是临时变量
    arr->PushBack(100);
    arr->PushBack(200); // 调用 T&& value; 对右值进行取引用 C++11 标准
    arr->PushBack(300);

    // 在这里我们存放的是基本数据类型，那么直接使用 等号 将其放入容器内部；这里可能会调用拷贝构造函数或者等号重载操作符

    for (size_t i = 0; i < arr->getSize(); i++)
    {
        cout << (*arr)[i] << " ";
    }

    cout << endl;
    

    delete arr;
}