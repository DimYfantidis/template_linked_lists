cmake_minimum_required(VERSION 3.19)
project(template_linked_lists)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(template_linked_lists
        list.cpp
        list.h
        main.cpp)
