find_package(Catch2 REQUIRED)

add_executable(test_main test_main.cpp)
target_link_libraries(test_main
    PRIVATE nkgt-utils
    PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(test_main)