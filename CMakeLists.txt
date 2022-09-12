cmake_minimum_required(VERSION 3.22)
project(ADSLab_1_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADSLab_1_2
        main.cpp
        Tree.cpp
        Tree.h)
