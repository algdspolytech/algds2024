cmake_minimum_required(VERSION 3.28)

project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  OVERRIDE_FIND_PACKAGE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${googletest_SOURCE_DIR}/googletest/include/gtest)



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