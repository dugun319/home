#include <iostream>
#include <string>

void star(int a = 5);
void msg(int id, std::string text = "");
void f(std::string text = " ", int a = 1);

void f(std::string text, int a) {
    for(int i = 0 ; i<a ; i++) {
        for(int j=0 ; j<10 ; j++) {
            std::cout<<text;
        }
        std::cout<<"_end";
        std::cout<<std::endl;
    }
}

void star(int a) {
    for(int i = 0 ; i<a ; i++) {
        std::cout<<'*';
    }
    std::cout<<std::endl;
}

void msg(int id, std::string text) {
    std::cout<<id<<' '<<text<<std::endl;
}

int main() {
    star();
    star(10);

    msg(10);
    msg(11, "Hello");

    f();
    f("%");
    f("@", 5);
}