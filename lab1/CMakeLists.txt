cmake_minimum_required(VERSION 2.8)	 

project(lab1)

set(SOURCE_EXE main.c)

set(SOURCE_LIB funcs.c)

add_library(funcs STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main funcs)