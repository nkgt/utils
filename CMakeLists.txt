cmake_minimum_required(VERSION 3.18)
project(nkgt-utils)

add_library(nkgt-utils
    src/noisy.cpp)

target_include_directories(nkgt-utils
    PUBLIC include)

target_compile_options(nkgt-utils
    PRIVATE $<$<CONFIG:Debug>:-Wall -Wextra -Wpedantic -Wconversion>
    PRIVATE $<$<CONFIG:Debug>:-fsanitize=address -fsanitize=leak -fsanitize=undefined>
    PRIVATE -std=c++17)