/** 
  * CodeEval task #110
  *
  * https://www.codeeval.com/open_challenges/110/
  * Fibonacci numbers
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <climits>

typedef std::string strnum_t;
typedef std::map<strnum_t, int> strnumbermap_t;
typedef std::pair<size_t, int> numberindexpair_t;


class StringNumberParser {
    public:
    StringNumberParser() {}

    inline static const int parse(const std::string & strnum) {
        // X millions X thouthands X hundred (X tens X digits | X ellevens)  
        std::istringstream s(strnum);
        std::string buf; 

        bool is_negative = false;
        
        // Check if negative
        s >> buf;

        if (buf == negative_) {
            is_negative = true;
            s >> buf;
        }

        int cur_number = 0,
            cur_index = INT_MAX,
            res = 0;

        do {
            numberindexpair_t p = get_number(buf);
            
            size_t new_index = p.first;
            int new_number = p.second;

            if (new_index < cur_index) {
                cur_number += new_number;
            }
            else {
                cur_number *= new_number;
                flush_(res, cur_number);
                cur_index = INT_MAX;
            }

            cur_index = new_index;
        } while (s >> buf);

        // last number
        flush_(res, cur_number);

        return is_negative ? -res : res;
    }


    /**
     * Get number from string representation or Zero if not a number;
     * @return priority_index, number
     */
    inline static const numberindexpair_t get_number(const std::string & strnum) {
        // Iterating over digit types
        for(auto it=strNumberLiterals_.begin(); it != strNumberLiterals_.end(); ++it) {
            size_t index = std::distance(strNumberLiterals_.begin(), it);

            auto jt = it->find(strnum);
            //auto jt = std::find(it->begin(), it->end(), strnum);
            if (jt != it->end()) {
                int number = jt->second;
                return std::make_pair(index, number);
            }
        }

        return std::make_pair(0,0);
    }

    private:
    static const strnumbermap_t digits_;

    static const strnumbermap_t ellevens_;
    static const strnumbermap_t tens_;

    static const std::vector<strnumbermap_t> strNumberLiterals_;

    static const strnum_t negative_;

    static void flush_(int &res, int& x) {
        res += x;
        x = 0;
    }
};


const std::map<strnum_t, int> StringNumberParser::digits_ = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3}, 
    {"four", 4}, 
    {"five", 5}, 
    {"six", 6}, 
    {"seven", 7}, 
    {"eight", 8}, 
    {"nine", 9}
};

const std::map<strnum_t, int> StringNumberParser::ellevens_ = {
    {"eleven", 11},
    {"twelve", 12}, 
    {"thirteen", 13}, 
    {"fourteen", 14}, 
    {"fifteen", 15}, 
    {"sixteen", 16}, 
    {"seventeen", 17}, 
    {"eighteen", 18},
    {"nineteen", 19}
};

const std::map<strnum_t, int> StringNumberParser::tens_ = {
    {"ten", 10},
    {"twenty", 20}, 
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90}
};

const std::vector<std::map<strnum_t, int> > StringNumberParser::strNumberLiterals_ = {
    StringNumberParser::digits_,
    StringNumberParser::ellevens_,
    StringNumberParser::tens_,
    {{"hundred", 100}},
    {{"thousand", 1000}},
    {{"million", 1000000}}
};


const strnum_t StringNumberParser::negative_ = "negative";


int main(int argc, char * argv[]) {
    using namespace std;

    ifstream f(argv[1]);

    string buf = "";

    while(getline(f, buf)) {
        cout << StringNumberParser::parse(buf) << endl;
    }
}

