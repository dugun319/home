#include <iostream>

int big(int a, int b);

int big(int a[], int size);

int big(int a, int b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}

int big(int a[], int size) {
    int max_num = a[0];

    for(int i = 0; i < size ; i++) {
        if(max_num < a[i]) {
            max_num = a[i];
        }
    }
    return max_num;
}

int main() {
    int arry[5] = {1, 9, -2, 8, 6};
    std::cout<<big(2, 3)<<std::endl;
    std::cout<<big(arry, sizeof(arry) / sizeof(int))<<std::endl;
}