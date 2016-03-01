#include <iostream>

class A {
public:
  A() {}
  virtual void f() const { std::cout << "A::f() called" << std::endl; }
};


class B: public A {
public:
  B() {}
  void f() const { std::cout << "B::f() called" << std::endl; }
};


int main() {
    A * obj = new B();
    obj->f();
    return 0;
}
