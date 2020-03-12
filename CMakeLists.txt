cmake_minimum_required(VERSION 3.15)
project(CSC340_CPP_Dictionary)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSC340_CPP_Dictionary main.cpp readData.h readData.cpp Dictionary.h Dictionary.cpp)
