/** 
  * CodeEval task #22
  *
  * https://www.codeeval.com/open_challenges/22/
  * Fibonacci numbers
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <vector>


int main(int argc, char * argv[]) {
    using namespace std;

    vector<size_t> fib_storage(2);

    fib_storage[0] = 0;
    fib_storage[1] = 1;

    ifstream f(argv[1]);

    string s_number;
    size_t number;

    while(f >> s_number) {
        number = atoi(s_number.c_str());
   
        size_t fib = 0;

        if(fib_storage.size() <= number) {
            fib_storage.reserve(number+1);

            for(size_t i = fib_storage.size(); i <= number+1; ++i) {
                fib_storage[i] = fib_storage[i-1] + fib_storage[i-2];
            }
        }

        cout << fib_storage[number] << endl;
    }

}




