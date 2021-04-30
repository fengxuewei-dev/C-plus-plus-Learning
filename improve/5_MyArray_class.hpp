#include "5_MyArray_class.h"

template<class T>
MyArray<T>::MyArray(int capacity){
    this->mCapacity = capacity;

    this->mSize = SIZE_MAX;

    this->pAddr = new T[capacity];    
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
    this->mCapacity = another.mCapacity;
    
    this->pAddr = another.pAddr;
}

template<class T>
void MyArray<T>::PushBack(T& value){

}