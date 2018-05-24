cmake_minimum_required(VERSION 3.10)
project(MapTree)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES Map.h)

add_executable(MapTree main.cpp Map.cpp)