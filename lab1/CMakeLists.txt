cmake_minimum_required(VERSION 3.5)

project(lab1)

set(SOURCE_LIB myLib.c)

set(SOURCE_EXE main.c)	

add_library(lib STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main lib)	