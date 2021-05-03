#include <iostream>
#include <cstring>



using namespace std;

class BaseException{
    public:
        virtual void what() = 0;
        virtual ~BaseException(){

        }
    protected:
        char *mError;
};

class MyOutOfRange : public BaseException{
    public:
        MyOutOfRange(const char * const error){
            cout << "MyOutOfRange(const char * const error)" << endl;
            this->mError = new char[strlen(error) + 1];
            strcpy(this->mError, error);
        }

        virtual void what(){
            cout << this->mError << endl;
        }

        virtual ~MyOutOfRange(){
            cout << "virtual ~MyOutOfRange()" << endl;
            if(this->mError != NULL){
                delete[] this->mError;
                this->mError = NULL;
            }
        }
};

double divide(int x, int y){
    if(y == 0){
        throw new MyOutOfRange("the y's value is zero!");
    }

    return x / y;
}

class Person{
    public:
        Person(const int age){
            if(age < 0 || age > 100){
                throw new MyOutOfRange("the age is greater than 0~100");
            }
            this->mAge = age;
        }
        int getAge(){
            return this->mAge;
        }
    private:
        int mAge;
};

void copy_str(char *target, const char* source){
    cout << "copy_str" << endl;
    if(target == NULL){
        throw new MyOutOfRange("the target is in invaild!");
    }

    if(source == NULL){
        throw new MyOutOfRange("the source is in invaild!");
    }
    // 这里如果重新开辟一个空间，那么就和传入进行的数据地址不想符合，出现赋值失败.
    // target = new char[strlen(source) + 1];
    // for(int i = 0; i < strlen(source); i++){
    //     *target = *source;
    //     target++;
    //     source++;
    // }
    // // *target = '\0';

    // cout << "target = " << *target << endl;
    // cout << "target = " << *source << endl;
    while(*source != '\0'){
        *target = *source;
        target++;
        source++;
    }
    *target = '\0';
}

void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test03(){
    try{
        const char *source = "abcddef";
        char buf[1024] = {0};

        copy_str(buf, source);
        cout << "buf = " << buf << endl;
    }catch(BaseException* e){
        e->what();
        delete e;
    }
}

void test02(){
    try{
        Person p(20);
        cout << p.getAge() << endl;
    }catch(MyOutOfRange* e){
        e->what();
        delete e;
    }
    
}

void test01(){
    try{
        divide(10 , 0);
    }catch(BaseException* e){ // 基类的指针指向派生类对象
        e->what();
        delete e;
    }

    // cout << "endl" << endl;
}