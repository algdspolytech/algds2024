cmake_minimum_required(VERSION 3.24)

project(lab1_test_project C CXX)

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

set(TEST_NAME lab1_test)

set(SOURCE_DIR ../../)

set(TEST_FILES
        dynamic_count_test.cpp
)

set(TEST_SOURCE_FILES
        ${SOURCE_DIR}/dynamic_count.c
        ${SOURCE_DIR}/trivial.c
)

enable_testing()

add_executable(
        ${TEST_NAME}
        ${TEST_SOURCE_FILES}
        ${TEST_FILES}
)

target_include_directories(
        ${TEST_NAME}
        PRIVATE ${SOURCE_DIR})

target_link_libraries(
        ${TEST_NAME}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})