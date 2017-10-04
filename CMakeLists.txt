cmake_minimum_required(VERSION 3.8)
project(Strings)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        string_funcs.c string_funcs.h string_tests.c string_tests.h)

add_executable(Strings ${SOURCE_FILES})