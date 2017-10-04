cmake_minimum_required(VERSION 3.8)
project(Strings)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        strings.c
        )

add_executable(Strings ${SOURCE_FILES})