cmake_minimum_required(VERSION 3.9)
project(szablony)

set(CMAKE_CXX_STANDARD 14)

add_executable(szablony source_files/main.cpp source_files/Matrix.cpp header_files/Matrix.h source_files/Lists.cpp header_files/Lists.h source_files/Para.cpp header_files/Para.h)