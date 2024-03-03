include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(t test.cpp)
target_link_libraries(t PRIVATE GTest::gtest_main)

target_include_directories(t PRIVATE ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(t)

enable_testing()