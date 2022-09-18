#include <iostream>
#include <string>

void square(int* n, int size) {
    for(int i=0 ; i<size ; i++) {
        n[i] = n[i] * n[i];
        std::cout<<"n[i] = "<<n[i]<<std::endl;;
    }
}

int& big1(int a, int b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}

int& big2(int& a, int& b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}


int main() {
    int m[3] = {1, 2, 3};
    square(m, 3);
    for(int i=0 ; i<3 ; i++) {
        std::cout<<m[i]<<' ';
    }

    std::cout<<std::endl;

    int x = 1;
    int y = 2;

    int& z = big1(x, y);

    std::cout<<"x1 = "<<x<<std::endl;
    std::cout<<"y1 = "<<y<<std::endl;
    //std::cout<<"z1 = "<<z<<std::endl;

    //z = 100;

    std::cout<<"x2 = "<<x<<std::endl;
    std::cout<<"y2 = "<<y<<std::endl;
    //std::cout<<"z2 = "<<z<<std::endl;

    int& w = big2(x, y);

    std::cout<<"x1 = "<<x<<std::endl;
    std::cout<<"y1 = "<<y<<std::endl;
    std::cout<<"w1 = "<<w<<std::endl;

    w = 100;

    std::cout<<"x2 = "<<x<<std::endl;
    std::cout<<"y2 = "<<y<<std::endl;
    std::cout<<"w2 = "<<w<<std::endl;

}