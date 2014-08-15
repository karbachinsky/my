#include <iostream>
#include <iomanip>

using namespace std;
typedef char byte;

int main(int argc, char * argv[]) {
        byte x = 16;
        byte mask = 0x80;
        size_t n = 0;

        for(size_t i=1; i<=7; ++i) {
                byte tmp = (x<<i);
                //cout <<(short)tmp << " " << (short)mask << endl;
                if( ((byte)(x<<i)&mask)^mask == 0x00 ) {
                        ++n;
                }
        }

        cout << n << endl;

        return 0;
}

