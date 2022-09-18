#include <iostream>

class Person {
private :
    static int sharedMoney;
public :
    int money;
    void addMoney(int money) {
        this->money += money;
    }

    //static int sharedMoney;    
    static void addShredMoney(int new_money) {
        sharedMoney += new_money;
    }
    static int getSharedMoney() {
        return sharedMoney;
    }
};

int Person::sharedMoney = 100;

int main() {
    Person::addShredMoney(50);
    std::cout<<"Original Shared money is "<<Person::getSharedMoney()<<std::endl;

    Person Han;
    Han.money = 100;
    Han.addShredMoney(100);

    Person Lee;
    Lee.money = 150;
    Lee.addMoney(200);
    Lee.addShredMoney(200);

    std::cout<<"Han.money\t= "<<Han.money<<"\t"<<"Lee.money\t= "<<Lee.money<<std::endl;
    std::cout<<"Han.sharedMoney = "<<Han.getSharedMoney()<<"\t"<<"Lee.sharedMoney = "<<Lee.getSharedMoney()<<std::endl;
}