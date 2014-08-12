/** 
  * CodeEval task #25
  *
  * https://www.codeeval.com/open_challenges/25/
  * Odd numbers from 1 to 99
  8
  * Author: I. Karbachinsky
  */


#include <iostream>


int main(int argc, char * argv[]) {
    for(unsigned short i=1; i<=99; i+=2) {
        std::cout << i << std::endl;
    }
}




