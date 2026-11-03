cmake_minimum_required(VERSION 3.16)
project(Studentai LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(studentai
    v0.1_projektas.cpp
    funkcijos.cpp
    funkcijos.h
    studentas.h
)
if(MSVC)
    target_compile_options(studentai PRIVATE /W4 /utf-8)
else()
    target_compile_options(studentai PRIVATE -O2 -Wall -Wextra -Wpedantic)
endif()

install(TARGETS studentai RUNTIME DESTINATION bin)