#include <iostream>

using namespace std;

class MyArray{
    friend ostream& operator<<(ostream& os,const MyArray& array);
    friend istream& operator>>(istream& is,const MyArray& array);
    public:
        MyArray(){
            this->len = 0;
            this->space = NULL;
        }
        MyArray(int len){
            if(len < 0){
                this->len = 0;
                return;
            }else{
                this->len = len;


                this->space = new int[this->len];
            }
        }
        MyArray(const MyArray& another){
            if(another.len >= 0){
                this->len = another.len;

                this->space = new int[this->len];
                for(int i = 0; i < this->len; i++){
                    this->space[i] = another.space[i];
                }
            }
        }
        ~MyArray(){
            if(this->space != NULL){
                delete[] this->space;
                this->space = NULL;
                this->len = 0;
            }
        }


        void setData(int index, int data){
            if(this->space != NULL){
                this->space[index] = data;
            }
        }
        int getData(int index) const{
            return this->space[index];
        }
        int getLen() const{
            return this->len;
        }

        MyArray& operator=(const MyArray& another){ 
            if(this == &another){
                return *this;
            }
            
            if(this->space != NULL){
                delete[] this->space;
                this->space = NULL;
                this->len = 0;
            }
            if(another.len >= 0){
                this->len = another.len;
                
                this->space = new int[this->len];

                for(int i = 0; i < another.len; i++){
                    this->space[i] = another.space[i];
                }
                
            }
            return *this;
        }
        int& operator[](int index) const{ // array1[i] = i + 10, 应该是 space[i] = i + 10; 返回space的引用
            // if (index >= this->len)
            // {
            //     return NULL;
            // }
        
            return this->space[index];
        }
        bool operator==(const MyArray& array){
            if(this == &array){
                return true;
            }
            if(this->len != array.len){
                return false;
            }
            for(int i = 0; i < array.len; i++){
                if(this->space[i] != array[i]){
                    return false;
                }
            }
            return true;
        } 
        bool operator!=(const MyArray& array){
            // if(this == &array){
            //     return false;
            // }
            // if(this->len != array.len){
            //     return true;
            // }
            // for(int i = 0; i < array.len; i++){
            //     if(this->space[i] != array[i]){
            //         return true;
            //     }
            // }
            // return false;
            return !(*this == array);
        }
    private:
        int len;
        int *space;
};

ostream& operator<<(ostream& os,const MyArray& array){
    for(int i = 0; i < array.len; i++){
        os << array[i] << " ";// array.operator[](MyArray * cost this, i) // 但是这里的 array 为const 也就是该 this指针为 const MyArray * const this, 类型不匹配进行报错，所以应该在运算符重载后面加上一个const
    }
    return os;
}
istream& operator>>(istream& is, const MyArray& array){
    cout << "input the array values, and the length is " << array.len << ":" << endl;
    for(int i = 0; i < array.len;i++){
        // cout << "the " << i << "th : ";
        cin >> array[i];
    }
    return is;
    /*
        input the array values, and the length is 10:
        1 2 3 4 5 6 7 8 9 10
        ---------------------
        1 2 3 4 5 6 7 8 9 10 
        array3 : 
        1 2 3 4 5 6 7 8 9 10 
    */
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    MyArray array1(10);

    // for(int i = 0; i < array1.getLen(); i++){
    //     // array1.setData(i, i + 10);
    //     array1[i] = i + 10;
    // }
    cin >> array1;

    cout << "---------------------" << endl;

    // for(int i = 0; i < array1.getLen(); i++){
    //     cout << "array1[" << i << "] = " << array1[i] << endl;
    // }
    cout << array1 << endl;


    MyArray array3(20);
    array3 = array1;

    cout << "array3 : " << endl;

    // for(int i = 0; i < array3.getLen(); i++){
    //    cout << "array3[" << i << "] = " << array3[i] << endl;
    // }
    cout << array3 << endl;
    array3[3] = 23;
    cout << (array1== array3) << endl;
    cout << (array1!= array3) << endl;

}