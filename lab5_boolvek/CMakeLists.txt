cmake_minimum_required(VERSION 3.24)
project(lab5_bool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")
add_executable(lab5_bool main.cpp inc/vectorBool.h)
