#include <iostream>

#include <vector> // 动态数组 可变数组

#include <algorithm>

using namespace std;

/*
    STL: 容器、算法、迭代器 
        container： 存放数据
            容器中是可以嵌套容器，此时内部的容器就称为 元素

            元素在容器中的位置的决定因素
            序列式容器：元素位置是由进入容器中的时间和地点有关
            关联式容器：与元素进入容器的先后顺序是没有关系的，什么数据存放在什么位置已经事先规定好了。。 容器内部存在一定的规则

        algorithm：算法；通过有限的步骤解决问题；是一些 函数模版

        iteratior：用来遍历容器中元素的指针，默认情况下，会指向第一个元素的位置，当为其进行++的时候，进行移动位置。对指针的操作都可以对迭代器进行操作。实际上 迭代器 是一个类，该类中重载了 一些操作运算符，同时该类中封装了一个指针，来指向元素的地址

    那么为什么会有上面的这些 STL 呢？ 可以分工开发容器和算法库，而迭代器是 容器 提供的外部接口，供算法进行调用 容器  容器提供迭代器
    容器 ---> 迭代器（桥梁） ---> 算法


    防函数、适配器

    1、STL 是一个内置到编译器中
    2、重要特点是：数据结构和算法分离

    每个容器都有一个 start 和 一个 end 指针，start 指向第一个元素，end 指向最后一个元素的下一个位置，当 start 移动之后，和 end 指针重合，说明遍历完成


*/
class Person{
    public:
        Person(int id, int age){
            this->mAge = age;
            this->mId = id;
        }
        ~Person(){
            cout << "~Person()" << endl;
        }

        void show(){
            cout << "id = " << this->mId << "  age = " << this->mAge << endl;
        }
    private:
        int mId;
        int mAge;
};

void ShowPerson(Person* p){
    p->show();
    delete p;
}
void PrintVector(int v){
    cout << v << endl;
}

int myCount(int* start, int *end, int value){
    // 算法，负责统计某个元素的个数
    int number = 0;
    while (start != end)
    {
        if(*start == value){
            number++;
        }
        start++;
    }
    return number;
}


void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test03(){
    vector<Person*> vp;

    vp.push_back(new Person(10, 20));
    vp.push_back(new Person(30, 30));
    vp.push_back(new Person(40, 40));

    vector<Person*>::iterator vpBegin = vp.begin();
    vector<Person*>::iterator vpEnd = vp.end();
    
    for_each(vpBegin, vpEnd, ShowPerson);// ShowPerson 回调函数


}

void test02(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();
 
    for_each(pBegin, pEnd, PrintVector);  // 算法来调用这些容器

}
void test01(){

    // 容器
    int arr[] = {0, 3, 5, 6, 8, 0, 9, 0};


    // 迭代器 开始位置
    int * pBegin = arr;      

    // 指向最后一个元素的下一个位置
    int * pEnd = &(arr[sizeof(arr) / sizeof(int)]);


    int count = myCount(pBegin, pEnd, 0);

    cout << count << endl;
}