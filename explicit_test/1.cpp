#include <iostream>

class MyClass {
public:
    explicit MyClass(const int a) {
        std::cout << "Constructor with parameters: " << a << std::endl;
    }
};

int main(int argc, char** argv) {
    MyClass obj = 5;
    return 0;
}

