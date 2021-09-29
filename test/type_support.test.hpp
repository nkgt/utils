#include <catch2/catch.hpp>
#include <nkgt/type_support.hpp>

#include <string>

class A {
public:
    int f(double);
};

int f(double);
int* g(double*);

TEST_CASE("Types are correctly demangled", "[type-support]") {
    REQUIRE(nkgt::type_name_v<int> == "int");
    REQUIRE(nkgt::type_name_v<int*> == "int*");
    REQUIRE(nkgt::type_name_v<decltype(&f)> == "int (*)(double)");
    REQUIRE(nkgt::type_name_v<decltype(&g)> == "int* (*)(double*)");
    REQUIRE(nkgt::type_name_v<decltype(&A::f)> == "int (A::*)(double)");

    // Horrible test ahead
#ifdef __clang__
    REQUIRE(nkgt::type_name_v<std::string> == "std::basic_string<char>");
#elif defined(__GNUC__)
    REQUIRE(nkgt::type_name_v<std::string> == "std::__cxx11::basic_string<char>");
#elif defined(_MSC_VER)
    REQUIRE(nkgt::type_name_v<std::string> == "DONT KNOW");
#endif
}