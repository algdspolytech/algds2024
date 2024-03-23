cmake_minimum_required(VERSION 3.22)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_matrix_operations
  test_matrix_operations.cpp
  matrix_operations.h
  matrix_operations.c
)
target_link_libraries(
  test_matrix_operations
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_matrix_operations)
