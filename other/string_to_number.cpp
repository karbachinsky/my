#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <vector>
#include <iomanip>


inline bool isDigitNative(const int c) {
    return (c == 1 || c == 2 || c == 3 || c == 4 || c ==5 || c == 6 || c ==7 || c == 8 || c == 9 || c == 0);
}

template<template<typename> class Container>
inline bool isDigitStl(const int c) {
    static const Container<char> digits  = {0,1,2,3,4,5,6,7,8,9};
    return digits.find(c) != digits.end();
}


inline bool isDigitClever(const int c) {
    return (((c >> 3) == 0) || c == 8 || c == 9);
}

inline bool isDigitChar(const int c) {
    const char x = (char)c;
    std::cout << std::ord(x) << std::endl;
    return (x > 47 && x < 58); 
}



int main() {
    int a = 0;

    std::cout << isDigitNative(1) << " " << isDigitNative(11) << std::endl;
    
    std::cout << isDigitClever(1) << " " << isDigitClever(11) << std::endl;
    
    std::cout << isDigitChar(1) << " " << isDigitChar(11) << std::endl;

    //std::cout << isDigitStl<std::vector>(1) << " " << isDigitClever<std::vector>(11) << std::endl;

    /*
    a = std::atoi("123");
    std::cout << a << std::endl;

    a = std::atoi("asd123asd");
    std::cout << a << std::endl;

    char *end;
    int base = 0;
    long b = 0;

    const char * str = "12312312asd";
    a = std::strtol(str, &end, base);
    std::cout << "End is " << end << " " << errno << std::endl;
    */

    return 0;
}
