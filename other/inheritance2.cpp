#include <iostream>

using namespace std;

class A {
   public:
     //virtual void f() = 0;
     virtual void f() { cout << "A" << endl; }
};

class B: public A{
   public:
     void f() { cout << "B" << endl; }
};

class C: public A{
   public:
     void f() { cout << "C" << endl; }
};

int main() {
    A * b = new B();
    A * c = new C();
    b->f(); // здесь будет вызываться метод класса B
    c->f(); // здесь будет вызываться метод класса C
}
