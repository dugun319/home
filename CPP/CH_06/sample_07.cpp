#include <iostream>
#include <string>

/*
void msg(int id) {
    std::cout<<id<<std::endl;
}
*/

int f(int a, int b) {
    return a + b;
}

/*
int f(int a = 3, int b = 5) {
    return a + b;
}
*/

void msg(int id, std::string s = " ") {
    std::cout<<id<<" : "<<s<<std::endl;
}

float Square(float a) {
    return a * a;
}

double Square(double a) {
    return a * a;
}

/*
int add(int a, int b) {
    return a + b;
}
*/

int add(int a, int& b) {
    b = a + b;
    return b;
}

int main() {
    std::cout<<Square(3.0)<<std::endl;
    std::cout<<Square(3.1)<<std::endl;

    int s = 10;
    int t = 20;

    std::cout<<"s = "<<s<<std::endl;
    std::cout<<"t = "<<t<<std::endl;

    add(5, s);
    add(10, t);

    std::cout<<"s = "<<s<<std::endl;
    std::cout<<"t = "<<t<<std::endl;

    msg(5, "Good Morning~");
    msg(6);

    f(7, 10);

}