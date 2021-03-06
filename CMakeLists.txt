cmake_minimum_required(VERSION 3.18)
project(nkgt-utils)

add_library(nkgt-utils
    src/noisy.cpp)

target_include_directories(nkgt-utils
    PUBLIC include)

target_compile_options(nkgt-utils
    PRIVATE $<$<CONFIG:Debug>:-g -Og>
    PRIVATE $<$<CONFIG:Debug>:-Wall -Wextra -Wpedantic -Wconversion>
    PRIVATE $<$<CONFIG:Debug>:-fsanitize=address -fsanitize=leak -fsanitize=undefined>
    PRIVATE $<$<CONFIG:Release>:-O3>
)

target_link_options(nkgt-utils
    PRIVATE $<$<CONFIG:Debug>:-fsanitize=address -fsanitize=leak -fsanitize=undefined>
)

set_target_properties(nkgt-utils PROPERTIES CXX_STANDARD 17)

if(NKGT_BUILD_TESTS STREQUAL "On")
    message(STATUS "Configuring tests...")
    add_subdirectory(test)
endif()