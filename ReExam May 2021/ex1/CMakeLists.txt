cmake_minimum_required(VERSION 3.20)
project(ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex1 ex01-main.cpp ex01-library.cpp ex01-library.h)
