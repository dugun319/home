#include <iostream>
#include <string>
using namespace std;

class Color {
private :
    string c;
public :
    Color() {c = "white"; cout<<"Basic constructor"<<endl;}
    Color(string c) {this->c = c; cout<<"Parameter Constructor"<<endl;}
    ~Color() {cout<<"Destructor"<<endl;}    
};

class Palette {
private :
    Color* p;
public :
    Palette() {p = new Color[3];}
    ~Palette() {delete [] p;}
};

int main() {
    Palette* p = new Palette();
    cout<<"New Palette"<<endl;
    delete p;

    string s1 = "123";
    string s2 = "246";

    int n = stoi(s1);
    int m = stoi(s2);

    cout<<n+m<<endl;

    string a("My name is Jane.");

    char ch = a[2];
    cout<<"char ch = "<<ch<<"hum"<<endl;
    cout<<"a.at(2) = "<<a.at(2)<<"hum"<<endl;

    if(a != "My name is John.") {
        cout<<"Different";
    }
    a += "~~";

    cout<<"a = "<<a<<endl;

    a[1] = 'Y';

    cout<<"a = "<<a<<endl;

}