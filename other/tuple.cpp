#include <iostream>
#include <tuple>

template<typename ... Types>
class MyTuple {
    MyTuple(Type ... args) {

    }

};


std::tuple<int,int> foo() {
    return std::tuple<int, int>(1,2);     
}

MyTuple<int,int> bar() {
    return std::tuple<int, int>(3,4);     
}

int main() {
    int a, b, c, d;
    std::tie(a,b) = foo();

    std::cout << "a = " << a << " b = " << b << std::endl;
    
    std::cout << "c = " << c << " d = " << d << std::endl;
}

