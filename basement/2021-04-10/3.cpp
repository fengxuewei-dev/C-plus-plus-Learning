#include <iostream>
#include <cstring>

using namespace std;
class Teacher{
    public:
        Teacher(){
            m_id = 0;
            m_name = NULL;
        }
        Teacher(int id, char *name){
            
            cout << "Teacher(int , char)" << endl;
            m_id = id;
 
            int len = strlen(name);
            m_name = (char*)malloc(sizeof(char) *(len + 1));
            strcpy(m_name, name);
        }

        Teacher(const Teacher& another){ // 深拷贝动作
            m_id = another.m_id;
            int len = strlen(m_name);
            m_name = (char*)malloc(sizeof(char)*(len+1));
            strcpy(m_name, another.m_name);
        }
        ~Teacher(){
            cout << "~Teacher" << endl;
            if(m_name != NULL){
                free(m_name);
                m_name = NULL;
            }

        }
        void print(){
            cout << "m_id = " << m_id << ", m_name = " << m_name << endl;
        }
    private:
        double m_id;
        char *m_name;
};


void test01(){
    /*
        当Teacher 在栈空间上开辟一个 空间 t1。内部有元素id和name指针
        t1 在构造函数中，用户为其手动开辟了一个内存空间。为name指针赋予了一个地址，该地址指向堆的某块儿空间。

        当执行 Teacher t2(t1);  的时候，调用 t2 的默认拷贝构造函数，这个时候 系统会将t2 的name指针也指向上面的内存控制，输出打印的数据和t1的内存数据是一致的。

        但是当执行完成的时候，需要对对象进行释放，先释放 t2再释放 t1, 当释放t2的时候，判断name != NULL，释放 t2 
        name所指向 堆中 开辟的地址，这个时候 在释放 t1 的时候，name指针不为null，释放内存，但是这个时候该内存已经倍释放掉了，所以会出现段错误 === 原因就是进行了浅拷贝


        需要手动来显示提供一个拷贝构造函数来完成深拷贝动作（只要函数成员有一个指针，需要手动提供一个拷贝函数，来完成深拷贝动作，防止指针指向相同地址 ，释放的时候出错）
    */
    char name[64] = "zhangsan01";
    Teacher t1(1, name);

    t1.print();

    Teacher t2(t1);     // 调用默认拷贝构造函数，系统不管你是什么类型的数据，都会使用 = 来相互赋值

    t2.print();
}

int main(void){
    test01();
    return 0;
}