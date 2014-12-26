/** 
  * CodeEval task #144
  *
  * https://www.codeeval.com/open_challenges/144/
  *
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <set>
#include <iterator>

typedef unsigned long long big_number_t;
typedef unsigned short digit_t;
typedef std::vector<big_number_t> digits_storage_t;  


inline void display(const digits_storage_t &digits) {
    for (auto it=digits.begin(); it != digits.end(); ++it) {
        const digit_t digit = std::distance(digits.begin(), it);
        std::cout << digit << ": " << *it;
        if (digit < 9)
            std::cout << ", ";
    }

    std::cout << std::endl;
}


inline short get_number_last_digit(const big_number_t & number) {
    const digit_t digit = number % 10;  
    return digit;
}


int main(int argc, char * argv[]) {
    using namespace std;

    ifstream f(argv[1]);

    string a_str, n_str;
    while (f >> a_str >> n_str) {
        const digit_t a = atoi(a_str.c_str());
        const big_number_t n = atoll(n_str.c_str()); 

        digits_storage_t digits = {0,0,0,0,0,0,0,0,0,0};
        digits_storage_t digits_circle;
        digits_circle.reserve(10);

        big_number_t x = 1;

        digit_t first_digit = get_number_last_digit(a);

        size_t f = n;
        while (f-- > 0) {
            x *= a;        

            const digit_t digit = get_number_last_digit(x);

            if (digit == first_digit && !digits_circle.empty())
                break;

            digits_circle.push_back(digit);
        }

        big_number_t k = n / digits_circle.size();

        for (auto it=digits_circle.begin(); it != digits_circle.end(); ++it) {
            digits[*it] = k;
        }

        size_t tail_size = n % digits_circle.size();   
        auto it = digits_circle.begin();
        while(tail_size-- > 0) {
            ++digits[*it];

            if (++it == digits_circle.end())
                it = digits_circle.begin();
        }

        display(digits);
    }
}




