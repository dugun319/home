#include <iostream>

class MyVector {
private :
    int* p;
    int size;
public :
    /*
    MyVector() {
        p = new int [100];
        size = 100;
    }
    */
    MyVector(int n = 100) {
        p = new int [n];
        size = n;
        std::cout<<"Contructor is called"<<std::endl;
    }
    ~MyVector() {
        delete [] p;
        std::cout<<"Destructor is called"<<std::endl;
    }
};

void fillLine(int n = 25, std::string c = "*") {
    for(int i = 0 ; i<n ; i++) {
        std::cout<<c;
    }
    std::cout<<std::endl;
}

int sum(int a, int b = 10) {
    return a + b;
}

int main() {
    fillLine();
    fillLine(10, "%");

    MyVector* v1;
    MyVector* v2;

    v1 = new MyVector();
    v2 = new MyVector(1024);

    std::cout<<"v1 & v2"<<std::endl;

    delete v1;
    delete v2;

    std::cout<<"sum(5)\t\t= "<<sum(5)<<std::endl;
    std::cout<<"sum(5, 10)\t= "<<sum(5, 10)<<std::endl;

}