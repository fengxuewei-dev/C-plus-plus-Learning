#include "4_templateClass_seg.h"


template<class T>
Person<T>::Person(T age){
    this->mAge = age;
}

template<class T>
void Person<T>::show(){
    cout << "age = " << this->mAge << endl;
}
