/** 
  * CodeEval task #19
  *
  * https://www.codeeval.com/open_challenges/19/
  * Author: I. Karbachinsky
  */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <bitset>

bool check_bits(int number, int pos1, int pos2) {
    std::bitset<sizeof(number)*8> bits(number);

    return bits[pos1-1] == bits[pos2-1];
}


int main(int argc, char * argv[]) {
    using namespace std;

    char delim = ',';
   
    string fileline = "";
    string s_number, s_bitpos1, s_bitpos2;
    
    ifstream f(argv[1]);
    //  while(!f.eof()) {
    while(f >> fileline) {

        stringstream ss(fileline);
        getline(ss, s_number, delim);  
        getline(ss, s_bitpos1, delim);
        getline(ss, s_bitpos2, delim);

        int number = atoi(s_number.c_str()),
        bitpos1 = atoi(s_bitpos1.c_str()),
        bitpos2 = atoi(s_bitpos2.c_str());

        cout << (check_bits(number, bitpos1, bitpos2) ? "true" : "false") << endl;
    }

}
