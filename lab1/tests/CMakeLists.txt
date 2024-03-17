cmake_minimum_required(VERSION 3.24)

project(lab1_tests C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)


include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(NAME lab1_test)

set(PATH ../source)

set(FILE func_test.cpp)

set(SOURCE_FILE ${PATH}/func.c)

enable_testing()

add_executable(
        ${NAME}
        ${SOURCE_FILE}
        ${FILE}
)

target_include_directories(
        ${NAME}
        PRIVATE ${PATH})

target_link_libraries(
        ${NAME}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${NAME})