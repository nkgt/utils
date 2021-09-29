find_package(Catch2 REQUIRED)

add_executable(test_main test_main.cpp)
target_link_libraries(test_main
    PRIVATE nkgt-utils
    PRIVATE Catch2::Catch2)

target_compile_options(test_main
    PRIVATE $<$<CONFIG:Debug>:-g -Og>
    PRIVATE $<$<CONFIG:Debug>:-Wall -Wextra -Wpedantic -Wconversion>
    PRIVATE $<$<CONFIG:Debug>:-fsanitize=address -fsanitize=leak -fsanitize=undefined>
    PRIVATE $<$<CONFIG:Release>:-O3>
)

target_link_options(test_main
    PRIVATE $<$<CONFIG:Debug>:-fsanitize=address -fsanitize=leak -fsanitize=undefined>
)

set_target_properties(test_main PROPERTIES CXX_STANDARD 17)

include(CTest)
include(Catch)
catch_discover_tests(test_main)