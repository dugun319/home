#include <iostream>

class Circle {
private : 
    int radius;
public :
    Circle(const Circle& c);
    Circle() { radius = 1;}
    Circle(int radius) {this->radius = radius;}
    double getArea() {return 3.14 * radius * radius;}
};

Circle::Circle(const Circle& c) {
    this->radius = c.radius;
    std::cout<<"Copy constructor is called radius = "<<radius<<std::endl;
}

int main() {
    Circle src(30);
    Circle dest(src);

    std::cout<<"The area of src = "<<src.getArea()<<std::endl;
    std::cout<<"The area of dest = "<<dest.getArea()<<std::endl;
}