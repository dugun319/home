#include <iostream>
#include <cstring>

class Person {
private :
    char* name;
    int id;
public :
    Person(int id, const char* name);
    Person(const Person& person);
    ~Person();
    void changeName(const char* name);
    void show() {std::cout<<id<<","<<name<<std::endl;}
};

Person::Person(int id, const char* name) {
    this->id = id;
    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name, name);
}

Person::Person(const Person& person) {
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char[len+1];
    strcpy(this->name, person.name);
    std::cout<<"Copy constructor is called, the name of original instance is "<<this->name<<std::endl;
}

Person::~Person() {
    if(name) {
        delete [] name;
    }
}

void Person::changeName(const char* name) {
    if(strlen(name) > strlen(this->name)) {
        return;
    }
    else {
        strcpy(this->name, name);
    }
}

int main() {
    Person father(1, "Kitae");
    Person daughter(father);

    std::cout<<"After construct daughter instance"<<std::endl;

    father.show();
    daughter.show();

    daughter.changeName("Grace");

    std::cout<<"After changing daughter instance"<<std::endl;

    father.show();
    daughter.show();

    return 0;

}