cmake_minimum_required(VERSION 3.10)
project(BigNumbersv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigNumbersv2 main.cpp BigNumbers.cpp BigNumbers.h BigNumbersExtended.cpp)