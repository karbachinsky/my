/**
 * Find square of two possibly intersected rectilinear rectangles considering integer overflow.
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <iostream>

int rect_square(int a, int b, int c, int d) {
    int l = std::abs(a-c);
    int r = std::abs(b-d);
    if (l < 0 || r < 0 || (r > 0 && l > INT_MAX / r))
        throw std::overflow_error("");
    return l*r;
}

int intersect_square(int a, int b, int c, int d, int e, int f, int g, int h) {
    try {
        int a_square = rect_square(a,b,c,d);
        int b_square = rect_square(e,f,g,h);

        std::printf("First square %d\n", a_square);
        std::printf("Second square %d\n", b_square);

        int s1 = std::max(a,e);
        int s3 = std::min(c,g);

        int s2 = std::max(b,f);
        int s4 = std::min(d,h);

        std::printf("intersect coords: %d %d %d %d\n",s1, s2, s3, s4);

        int intersect_square = 0;
        if (s3 > s1 && s4 > s2)
            intersect_square = rect_square(s1,s2,s3,s4);

        int res = a_square + b_square - intersect_square;
        if (0 > res)
            throw std::overflow_error("");
    }
    catch (std::overflow_error &e) {
        std::printf("Got overflow");
        return -1;
    }
}

int main() {
    std::printf("Simple intersection: %d\n", intersect_square(-4,1,2,6,0,-1,4,3));
    std::printf("No intersection: %d\n", intersect_square(-4,1,2,6,4,1,8,5));
    std::printf("One inside the other: %d\n", intersect_square(-4,1,2,6,-2,2,0,4));
    std::printf("Rectangles are different dots: %d\n", intersect_square(-1,1,-1,1,-2,2,-2,2));
    std::printf("Rectangles are the same dots: %d\n", intersect_square(-1,1,-1,1,-1,1,-1,1));
    std::printf("Check overflow: %d\n", intersect_square(0,0,INT_MAX-1,INT_MAX-1,-1,1,-1,1));
}
