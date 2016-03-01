#include <iostream>

int * foo() {
    int a = 5;
    return &a;
}

int main() {
    int * p = foo();

    std::cout << *p << std::endl;
    
    *p = 10;

    std::cout << *p << std::endl;

}

