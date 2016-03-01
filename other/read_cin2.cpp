#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string buf;

    while(std::getline(std::cin, buf)) {
        std::cout << buf << std::endl;
    }

    return 0;
}

