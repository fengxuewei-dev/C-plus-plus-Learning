#pragma once

#include <iostream>

using namespace std;

template<class T>
class Person{
    public:
        Person(T age);

        void show();

        static int a;
    private:
        T mAge;
};

template<class T> int Person<T>::a = 0;
