/** 
  * CodeEval task #3
  *
  * https://www.codeeval.com/open_challenges/4/
  * Author: I. Karbachinsky
  */


/* FIXME: Using sieve */

#include <iostream>
#include <cstddef>
#include <vector>

typedef std::vector<size_t> primes_t;

int main(int argc, char * argv[]) {
    const size_t THRESHOLD = 1000;

    size_t prime = 0; // polindrom prime

    std::vector<bool> sieve(THRESHOLD, true); 

    for(size_t i=2; i*i<= THRESHOLD; ++i ) {
        if(sieve[i]) {
            size_t j = i*i;
            while(j <= THRESHOLD) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    for(size_t i=THRESHOLD-1; i>1; i-=2) {
        if(sieve[i]) {
            // Check is polindrom
            size_t n = i, rev =0;
            while (n > 0) {
                rev = rev * 10 + n % 10;
                n = n / 10;
            }

            if(i == rev) {
                prime = i;
                break;
            }
        }

    }


    std::cout << prime << std::endl;
}

