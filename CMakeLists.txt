CMAKE_MINIMUM_REQUIRED(VERSION 3.28)

project(TinkerVM)

add_executable(
    stackbench
    inc/arr_stack.hpp
    inc/list_stack.hpp
    src/main.cpp
)