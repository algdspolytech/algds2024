cmake_minimum_required(VERSION 3.24)

project(Project1_test C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
       testlab1
       ../Project1/funcs.cpp
       test.cpp
)
target_link_libraries(
        testlab1
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testlab1)