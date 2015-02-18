#define NDEBUG

#include <iostream>
#include <vector>
#include <algorithm>

#include "debug.hpp"
#include "kth_ordered_statistic.hpp"


int main() {
    //vector<int> a = {4,5,3,6,7,8,9,2,1,0};
    std::vector<int> a = {8,9,2,3,4,7,6,5,0,1};

    //nth_element(a.begin(), a.begin() + 2, a.end());

    DEBUG_ITERABLE("Starting array", a.begin(), a.end());

    for (size_t i=0; i<a.size(); ++i) { 
        auto it = algo::kth_ordered_statistic<std::vector<int>::iterator, int>(a.begin(), a.end(), i); 
        std::cout << i <<"-th ordered statistic: " << *it << std::endl;
    }
}

