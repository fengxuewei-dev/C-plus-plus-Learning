#include <iostream>

using namespace std;

/*
    this指针并不是 const Test* 类型的，因此可以通过它来修改内部的数据成员的值
    但是不能操作它本身。也就是 Test *const this;

    但是如果，我不想让用户在程序中通过this指针来修改其他的数据成员，应该怎么做呢？
        就在该类的成员函数后面加 const
            例如： double getX() const{ // 该const是修饰形参this指针，此时this类型为 const Test * const this;
                // 类的成员函数（普通函数不具备该性能）
            }

    this 指针代表了指定调用该函数的 对象地址。是 Complex * const this 类型，我们可以通过它来修改内部的数据成员；但是不能修改它的指向，因为 这里的 const 修饰的 指针 this 指针，说明这个指针是常量，不能修改它的内容

    const 修饰的是和他最接近的内容.
*/

class Test{
    public:
        Test(){

        }
        Test(double x, double y){
            this->m_x = x;
            this->m_y = y;
        }
        double getX(){  // double getX(Test *this) 默认一个this指针传递进来，指向当前调用该API的对象地址。这就是之前讨论的 函数不占用 类的内存空间.
            this->m_x = 20;     // this 指针不是 const Test * 类型的
            
            // this++; this 指针是 Test * const 类型的 内容可以修改，但是本身的值是不能修改的 

            return this->m_x;
        }
        double getY() const{
            // this->m_y = 10; // 报错
            return this->m_y;
        }
    private:
        double m_x;
        double m_y;
};

// 上面的代码等效于
#if 0
struct Test{
    double m_x;
    double m_y;
};

void Test_Init(struct Test* pthis, double x, double y){
    pthis->m_y = y;
    pthis->m_x = x;
}

double Test_GetX(struct Test* pthis){
    return pthis->m_x;
}
double Test_GetY(struct Test* pthis){
    return pthis->m_y;
}
#endif
void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Test t1(10, 30);
    Test t2(20, 40);

    cout << t1.getX() << endl;
    cout << t2.getX() << endl;
}