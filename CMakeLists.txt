cmake_minimum_required(VERSION 3.8)
project(Strings)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        strings.c
        string_tests.c
        string_funcs.c
        std_string_funcs.c
        util.h
        )

add_executable(Strings ${SOURCE_FILES})