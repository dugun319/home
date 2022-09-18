#include <iostream>

class MyClass {
private : 
    int size;
    int *element;
public :
    MyClass(int size) {
        this->size = size;
        element = new int [size];
        for(int i = 0 ; i<size ; i++) {
            element[i] = 0;
        }
    }
    MyClass(MyClass& c) {
        this->size = c.size;
        element = new int [c.size];
        for(int i=0 ; i<c.size ; i++) {
            element[i] = c.element[i];
        }
    }
    ~MyClass() {
            delete [] element;
        }
};

class Student {
private : 
    std::string name;
    std::string id;
    double grade;
public : 
    Student(const Student& c) {
        name = c.name;
        id = c.id;
        grade = c.grade;
    }
};

class Student2 {
private :
    std::string *pName;
    std::string *pId;
    double grade;
public :
    Student2(const Student2& c) {
        pName = c.pName;
        pId = c.pId;
        grade = c.grade;
    }
};