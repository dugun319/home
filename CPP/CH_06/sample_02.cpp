#include <iostream>

int sum(int a, int b);

int sum(int a);

int sum(int a, int b) {
    int min;
    int max;
    int sum_num = 0;

    if(a > b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }

    for(int i = min ; i < max+1 ; i++) {
        sum_num += i;
    }

    return sum_num;
}

int sum(int a) {
    int sum_num = 0;

    if(a<=0) {
        return 0;
    }
    else {
        for(int i = 0 ; i < a+1 ; i++) {
            sum_num += i;
        }
    }

    return sum_num;
}

int main() {

    std::cout<<"sum(3, 5)\t= "<<sum(3, 5)<<std::endl;
    std::cout<<"sum(3)\t\t= "<<sum(3)<<std::endl;
    std::cout<<"sum(100)\t= "<<sum(100)<<std::endl;
}