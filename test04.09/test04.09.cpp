#include <iostream>
#include <string>

using namespace std;

class A {
    string name;
    string surname;
public:
    A(){}
    A(string name, string surname) :name(name), surname(surname){}

    string getName() { return name; }
    string getSurname() { return surname; }
    friend virtual ostream& operator<<(ostream& cout, A& op) {
        cout << op.getName();
    }
};

class B : virtual public A {
    string school;
public:
    B(){}
    B(string name, string surname, string school):A(name, surname), school(school){}
};

class C : virtual public A {
    string workplace;
public:
    C() {}
    C(string name, string surname, string workplace) :A(name, surname), workplace(workplace) {}
};

class D : public B, public C {
public:
    D(){}
    D(string name, string surname, string school, string workplace):B(name, surname, school), C(name, surname, workplace){}
};

ostream& operator<<(ostream& cout, int a) {
    cout << a;
}
int main()
{
    /*D d("name", "surname", "school", "workplace");
    cout << d.getName();*/
    /*B b("name", "surname", "school");
    cout << b;*/
    operator<<(cout, 5);
}