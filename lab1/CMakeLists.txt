cmake_minimum_required(VERSION 3.10)
project(lab1)

# Устанавливаем переменные CMAKE_C_COMPILER и CMAKE_CXX_COMPILER
set(CMAKE_C_COMPILER "C:\Users\leoni\mingw64\bin\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\Users\leoni\mingw64\bin\g++.exe")

# Добавляем исполняемый файл вашего проекта
add_executable(lab1 main.c)

# Добавляем исполняемый файл тестов
add_executable(lab1Tests test1.cpp test2.cpp)

# Добавляем папку с исходными файлами Google Test
add_subdirectory(C:\Users\leoni\Downloads\googletest-main\googletest-main\googletest)

# Включаем заголовочные файлы Google Test в проект
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Связываем Google Test с исполняемым файлом тестов
target_link_libraries(lab1Tests gtest gtest_main)

# Опционально: добавляем тесты в CTest
enable_testing()
add_test(NAME lab1Tests COMMAND lab1Tests)
