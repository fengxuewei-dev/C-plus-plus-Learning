#include <iostream>
#include <cmath>

using namespace std;

class Point{
    public:
        Point(){
            this->x = 0;
            this->y = 0;
        }
        Point(double x, double y){
            this->x = x;
            this->y = y;
        }
        Point(const Point &p){
            this->x = p.x;
            this->y = p.y;
        }
        double getX(){
            return this->x;
        }
        double getY(){
            return this->y;
        }
    private:
        double x;
        double y;
};

class Circle{
    public:
        Circle(Point c, double R) : c1(c){
            this-> Radius = R;
        }
        bool getIN(Point another){
            double distance = sqrt(
                (another.getX() - this->c1.getX()) * (another.getX() - this->c1.getX()) + 
                (another.getY() - this->c1.getY()) * (another.getY() - this->c1.getY())
            );
            if (distance > this->Radius){
                return false;
            }
            return true;
        }
    private:    
        double Radius;
        Point c1;
};



void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Point p1;
    Circle c1(p1, 10);

    Point p2(20, 20);

    if(c1.getIN(p2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}