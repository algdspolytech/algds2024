cmake_minimum_required(VERSION 3.23)
project(project)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

add_executable(project main.c)

add_subdirectory(tests)
