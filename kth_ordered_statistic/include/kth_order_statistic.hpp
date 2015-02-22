

/* K-th order statistic evaluator
 * 
 * The same as nth_element in stl library.
 * 
 * Author: I. Karbachinsky <igorkarbachinsky@mail.ru> 2014
 */


#include <iostream>
#include <cassert>
#include "debug.hpp"

namespace algo {
    
template<class InputIterator, class T>
const InputIterator KthOrderStatistic(const InputIterator begin, const InputIterator end, size_t k) {
    size_t n = std::distance(begin, end);

    DEBUG("", std::endl);
    DEBUG_ITERABLE("Array", begin, end);
    DEBUG("k", k)
    DEBUG("n", n)

    assert(n >= k); 

    auto it = begin,
         jt = end-1;

    auto pivot = begin + n/2;
    const T pivot_value = *pivot; 

    DEBUG("Pivot value", pivot_value);

    do {
        while (*it < pivot_value) {
            ++it;
        }
        while (*jt > pivot_value) {
            --jt;
        }

        if (it < jt) {
            DEBUG("Swap it", *it);
            DEBUG("Swap jt", *jt);

            iter_swap(it, jt);
            it++; jt--;
        }
    } while (it < jt);

    pivot = it;

    size_t pivot_n = std::distance(begin, pivot);

    DEBUG_ITERABLE("Array after rearranging", begin, end);
    DEBUG("Pivot position after rearranging", pivot_n);

    if (pivot_n == k) {
        DEBUG("FOUND on positon: ", pivot_n);
        return pivot;
    }
    if (pivot_n > k) 
        return KthOrderStatistic<InputIterator, T>(begin, pivot, k);
    
    return KthOrderStatistic<InputIterator, T>(pivot, end, k - pivot_n);
}

} // namespace algo


