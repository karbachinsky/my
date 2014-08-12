/** 
  * CodeEval task #21
  *
  * https://www.codeeval.com/open_challenges/21/
  * Sum of digits
  *
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <vector>


int main(int argc, char * argv[]) {
    using namespace std;

    ifstream f(argv[1]);

    string s_number;

    while(f >> s_number) {
        size_t number = (size_t) atoi(s_number.c_str());
        
        size_t sum = 0;

        while(number != 0) {
            sum += number%10;
            number /= 10;
        }

        cout << sum << endl;
    }

}




