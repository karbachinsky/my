#include <vector>
#include "kth_order_statistic.hpp"
#include "gtest/gtest.h"

//#undef NDEBUG
//#include "debug.hpp"
#include <iostream>

namespace {
 
typedef std::vector<int> Numbers;
typedef std::vector<float> FloatNumbers;


template<class T, class I>
void CheckData(T &data, T &expected) {
    for (size_t i=0; i<data.size(); ++i) { 
        T data_copy = data;
        DEBUG_ITERABLE("data", data_copy.begin(), data_copy.end());
        auto jt = algo::KthOrderStatistic<typename T::iterator, I>(data_copy.begin(), data_copy.end(), i); 

        EXPECT_EQ(*jt, expected[i]);
    }
}

TEST(KOrderedStatistic, BasicBehavior) {
    Numbers data = {4,5,3,6,7,8,9,2,1,0};
    Numbers expected_statistics = {0,1,2,3,4,5,6,7,8,9};

    CheckData<Numbers, int>(data, expected_statistics);
}

TEST(KOrderedStatistic, DuplicateNumbers) {
    Numbers data = {16,18,10,16,12};
    Numbers expected_statistics = {10,12,16,16,18};

    CheckData<Numbers, int>(data, expected_statistics);
}


TEST(KOrderedStatistic, SmallSet) {
    Numbers data = {1,2};
    Numbers expected_statistics = {1,2};

    CheckData<Numbers, int>(data, expected_statistics);

    Numbers data2 = {5};
    Numbers expected_statistics2 = {5};

    CheckData<Numbers, int>(data2, expected_statistics2);
}


TEST(KOrderedStatistic, FloatNumbers) {
    FloatNumbers data = {4.1,5.2,3.3,6.4,7.5,8.6,9.7,2.8,1.9,0.0};
    FloatNumbers expected_statistics = {0.0,1.9,2.8,3.3,4.1,5.2,6.4,7.5,8.6,9.7};

    CheckData<FloatNumbers, float>(data, expected_statistics);
}

} // namespace


