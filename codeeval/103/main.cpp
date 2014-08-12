/** 
  * CodeEval task #103
  *
  * https://www.codeeval.com/open_challenges/4/
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <cstddef>
#include <cstdlib>

// map number => [count, position]
typedef std::map<size_t, std::pair<size_t,size_t> > numbers_map_t;

/** Storage class for numbers.
  * Contents hash where keys are numbers and values are pairs where first element 
  * is amount of gamers signed such number and second is a position of last gamer.
  */
class NumberStorage {
    public:
    NumberStorage() {}
    
    /** Add number to storage
      * 
      * @param <size_t> number
      * @param <size_t> position
      */
    void add(size_t number, size_t position) {
        ++_numbers[number].first;
        _numbers[number].second = position;
    }

    /** Get issue response.
      *
      */
    size_t get_min_uniq_pos() const {
        size_t min = 10;
        int min_pos = -1;

        for(numbers_map_t::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it) {
            if( (it->second).first == 1 ) {
                if( it->first < min) {
                    min = it->first;
                    min_pos = (it->second).second;
                }
            }
        }

        return min_pos;
    }

    private:
    numbers_map_t _numbers;    
};



int main(int argc, char * argv[]) {
    using namespace std;

    ifstream f(argv[1]);

    string line;
    while(getline(f, line)) {
        stringstream buf(line);

        NumberStorage numbers;

        string s_number;

        size_t pos = 0;
        while(buf >> s_number) {
            numbers.add( (size_t)atoi(s_number.c_str()), pos++);
        }

        size_t min_number_pos = numbers.get_min_uniq_pos();

        // Starting from 1
        cout << (min_number_pos + 1)<< endl;
    }

}

