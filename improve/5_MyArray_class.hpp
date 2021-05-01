#include "5_MyArray_class.h"

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

// template<class T>
// void MyArray<T>::PushBack(T& value){

// }