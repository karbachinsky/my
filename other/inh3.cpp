#include <iostream>

class A {
public:
    A() {std::cout << "A is called" << std::endl; a_ = 1;}
    virtual void foo() {
        std::cout << "A value is: " << a_ << std::endl;
    }
protected:
    int a_;
};

class B : public A {
public:
    B() {a_ = 12;}
    virtual void foo() {
        std::cout << "B value is: " << a_ << std::endl;
    }
};





int main() {
    //A *a = new A();

    int * a = new int();
    int * b = new int();


    std::cout << "a = " << *a << std::endl;
    std::cout << "b = " << *b << std::endl;
    //a.foo();

    //B b;
    //b.foo();
    return 0;
}
