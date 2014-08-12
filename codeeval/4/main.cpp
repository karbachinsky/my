/** 
  * CodeEval task #4
  *
  * https://www.codeeval.com/open_challenges/4/
  * Author: I. Karbachinsky
  */


// FIXME: Use sieve

#include <iostream>
#include <cstddef>
#include <vector>

typedef std::vector<size_t> primes_t;

int main(int argc, char * argv[]) {
    const size_t N = 1000;

    size_t cnt = 1; // count on found primes
    unsigned long  n = 3; // number to start from
    size_t sum = 2; // initial sum

    primes_t primes(1,2); // list of found primes
    primes_t::const_iterator it;
    bool is_prime;

    primes.reserve(N);
 
    while(cnt != N) {
        is_prime = true;
        // checkiing for delimeters. Checkinig only in currently found primes
        for(it=primes.begin(); it != primes.end(); ++it) {
            if(n%*it == 0) {
                is_prime = false;
                break;
            }
        }

        if(is_prime) {
            primes.push_back(n);
            sum += n;
            ++cnt;
        }

        // Don't check even numbers
        n += 2;
    }
    
    std::cout << sum << std::endl;
}

