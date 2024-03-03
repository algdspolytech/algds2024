cmake_minimum_required(VERSION 3.23)
project(untitled4)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

add_executable(untitled4 main.c)

add_subdirectory(tests)