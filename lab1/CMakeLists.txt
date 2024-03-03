cmake_minimum_required(VERSION 3.24)
project(alg_lab1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  task_tests
  task_tests.cpp
  FieldRoutesCalculate.h
  FieldRoutesCalculate.c
)
target_link_libraries(
  task_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(task_tests)