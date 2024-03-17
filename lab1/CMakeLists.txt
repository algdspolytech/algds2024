cmake_minimum_required(VERSION 3.23)

project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(
  test_funcs
  test_funcs.cpp
  funcs.c
  funcs.h
  
)	

target_link_libraries(
    test_funcs 
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test_funcs)