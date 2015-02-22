cmake_minimum_required(VERSION 2.8.4)
project(algo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp include/kth_order_statistic.hpp include/debug.hpp)

include_directories(include/)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

MESSAGE("Gtest include directory: ${GTEST_INCLUDE_DIRS}")

add_executable(algo_test tests/gtest_main.cpp tests/algo.hpp)
target_link_libraries(algo_test libgtest.a libgtest_main.a)

################################
# Unit Tests
################################
add_test(algo_test algo_test)
