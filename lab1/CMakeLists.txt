cmake_minimum_required(VERSION 3.00)
 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
include_directories(googletest)
include_directories(include)

add_definitions("-Wall -g")

project(test)

add_executable(test gtest.cpp func.c)
target_link_libraries(test libgtest libgtest_main)
target_link_libraries(test gtest gtest_main)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
gtest_discover_tests(test)
