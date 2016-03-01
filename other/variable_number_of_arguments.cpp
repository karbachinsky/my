#include <iostream>


void foo(int a, ...) {
   int *p = &a;

   while (*p) {
       std::cout << "arg = " << *p << std::endl;
       p++;
   }

}


int main () {
    foo(1, 2, 3, 4, 5);
}


