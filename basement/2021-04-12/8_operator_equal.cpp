#include <iostream>
#include <cstring>

using namespace std;

class Students{
    
    friend ostream& operator<<(ostream& os, Students& st1);
    friend istream& operator>>(istream& is, Students& st1);

    public:
        Students(){
            this->id = 0;
            this->name = NULL;
        }
        Students(int id, char *name){
            this->id = id;
            // this->name = name;
            int len = strlen(name);
            
            this->name = new char[len + 1];

            strcpy(this->name, name);
        }
        ~Students(){
            if(this->name != NULL){
                delete[] this->name;
                this->name = NULL;
            }
            this->id = 0;
        }

        Students(const Students& st1){ // 拷贝构造函数 是 const Student& st1.
            this->id = st1.id;
            // this->name = name;
            int len = strlen(st1.name);
            
            this->name = new char[len + 1];

            strcpy(this->name, st1.name);
        }
        Students& operator=(Students& st1){
            // 防止自身赋值
            if(this == &st1){
                // 等号左右的式子是一样的；赋值没有意义
                cout << "no valid" << endl;
                return *this;
            }
            // 1. 先将自身之前额外开辟的空间释放掉

            if(this->name == NULL){
                delete[] this->name;
                this->name = NULL;
            }

            // 3. 进行深拷贝
            this->id = st1.id;
            
            int len = strlen(st1.name);

            this->name = new char[len+1];

            strcpy(this->name, st1.name);

            return *this;
        }
    private:
        int id;
        char *name;
};

ostream& operator<<(ostream& os, Students& st1){
    os << "Student: id = " << st1.id << "\t" << st1.name << endl;
    return os;
}
istream& operator>>(istream& is, Students& st1){
    cout << "id: ";
    is >> st1.id;
    char *temp;
    cout << "name: ";
    is >> temp;
    int len = strlen(temp);
    st1.name = new char[len + 1];
    strcpy(st1.name, temp);
    return is;
}
 
void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    // st1 保存在栈中，内部数据成员包含 int id, char * name. name指针指向的是 堆中开辟的空间。
    Students st1(1, (char*)"zhangsan");


    Students st2(2, (char*)"lisi");
    // st2 = st2; // no valid 
    Students st3, st5;
    st5 = st3 = st1;      // 调用 Students 的赋值操作符， 没有给出则是默认的.这里是定义好的.
    
    cout << st3;
    cout << st5;
    cout << st1;

    Students st4;
    cin >> st4;
    cout << st4;
}