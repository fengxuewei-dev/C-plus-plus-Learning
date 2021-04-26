#include <iostream>

using namespace std;

/*
    判断两个立方体是否相等
    成员函数、全局函数
*/

class Cube{
    public:
        friend bool isEqual(const Cube& c1, const Cube & c2);
        Cube(){
            this->m_a = 0;
            this->m_b = 0;
            this->m_c = 0;
        }
        Cube(double a, double b, double c){
            this->m_a = a;
            this->m_b = b;
            this->m_c = c;
        }
        bool isEqual2(const Cube& another){
            if(this->m_a == another.m_a && this->m_b == another.m_b && this->m_c == another.m_c){
                return true;
            }
            return false;
        }
    private:
        double m_a;
        double m_b;
        double m_c;
};

// 判断两个立方体是否相等
bool isEqual(const Cube& c1, const Cube & c2){
    if(c1.m_a == c2.m_a && c1.m_b == c2.m_b && c1.m_c == c2.m_c){
        return true;
    }
    return false;
}

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test02(){
    Cube c1(10, 20 , 30);
    Cube c2(120, 20 , 30);

    if(c1.isEqual2(c2)){
        std::cout << "c1 == c2" << std::endl;
    }else{
        std::cout << "c1 != c2" << std::endl;
    }
}
void test01(){
    Cube c1(10, 20 , 30);
    Cube c2(10, 20 , 30);

    if(isEqual(c1, c2)){
        std::cout << "c1 == c2" << std::endl;
    }else{
        std::cout << "c1 != c2" << std::endl;
    }
}