cmake_minimum_required(VERSION 2.8.4)
project(kth_ordered_statistic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp kth_ordered_statistic.hpp debug.hpp)

add_executable(kth_ordered_statistic ${SOURCE_FILES})

