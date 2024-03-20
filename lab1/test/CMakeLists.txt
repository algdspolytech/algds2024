cmake_minimum_required(VERSION 3.27)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(test ${GTEST_LIBRARIES})
