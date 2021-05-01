#ifndef _MYARRAY_CLASS_H_
#define _MYARRAY_CLASS_H_

#include <iostream>
using namespace std;

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
            this->pAddr[this->mSize++] = value;
        }
        

    private:
        int mCapacity;  // 容量
        int mSize;      // 存放多少元素
        T* pAddr;       // 数据元素的首地址

};

#endif
