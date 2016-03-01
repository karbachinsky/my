#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string buf;
    int a, b, c;

    std::getline(std::cin, buf);
    
    std::stringstream ss(buf);

    ss >> a >> b >> c;

    std::cout << a << " " << b << " " << c << std::endl;
    //std::cout << buf << std::endl;

    return 0;
}

