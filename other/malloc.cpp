#include <iostream>
#include <cstdlib>

int main() {
    int *a = new int(10);
    std::free(a);
    std::cout << *a << std::endl;
    *a = 100;
    std::cout << *a << std::endl;

    return 0;
}
