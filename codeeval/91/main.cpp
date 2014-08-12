/** 
  * CodeEval task #113
  *
  * https://www.codeeval.com/open_challenges/113/
  * Multiply elements in lists 
  *
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include <vector>

typedef unsigned short ushort_t;
typedef std::vector<size_t> numbers_t;

int main(int argc, char * argv[]) {
    using namespace std;

    ifstream f(argv[1]);

    string buf, linebuf;

    while(getline(f, buf)) {
        stringstream sbuf(buf); 

        numbers_t list;   
        bool is_second_list = false;
        ushort_t i = 0;

        // Iterating over each number
        while(sbuf >> linebuf) {
            if(linebuf == "|") {
                is_second_list = true;
                continue;
            }
    
            ushort_t number = (ushort_t) atoi(linebuf.c_str());

            if(!is_second_list) {
                list.push_back((size_t)number);
            }
            else {
                list[i] *= number;
                cout << list[i];
                ++i;
                if(i != list.size()) {
                    cout << " ";
                }
            }
        }
        
        cout << endl;
    }

}




