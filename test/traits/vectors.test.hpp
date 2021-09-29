#include <catch2/catch.hpp>
#include <nkgt/traits/vectors.hpp>

#include <string>

struct vec3_int { int x, y, z; };
struct vec3_const_int { const int x = 1, y = 1, z = 1; };
struct vec3_int_wrong_name { int x, y, w; };
struct vec3_double { double x, y, z; };
struct vec3_mixed_type { int x, y; double z; };

struct vec3_static_z { int x, y; static int z; };
int vec3_static_z::z = 3;

// Just one const data member makes the type not uniform
struct vec3_const_z { int x, y; const int z; };

struct vec3_non_numeric { std::string x, y, z; };
struct vec3_more_members { int x, y, z, a; };
struct vec3_xyz_methods { int x(); int y(); int z(); };

TEST_CASE("is_vec3_like traits recognizes the correct types", "[traits-vector]") {
    SECTION("Numerical data members are acceptable") {
        REQUIRE(nkgt::is_vec3_like_v<vec3_int>);
        REQUIRE(nkgt::is_vec3_like_v<vec3_double>);
        REQUIRE(nkgt::is_vec3_like_v<vec3_static_z>);
        REQUIRE(nkgt::is_vec3_like_v<vec3_const_int>);
    }

    SECTION("Non-numerical data members are rejected") {
        REQUIRE(!nkgt::is_vec3_like_v<vec3_non_numeric>);
    }

    SECTION("Wrong naming is rejected") {
        REQUIRE(!nkgt::is_vec3_like_v<vec3_int_wrong_name>);
    }

    SECTION("Non-static data members must have uniform numerical type.") {
        REQUIRE(!nkgt::is_vec3_like_v<vec3_mixed_type>);
        REQUIRE(!nkgt::is_vec3_like_v<vec3_const_z>);
    }

    SECTION("Member methods with the same name are rejected") {
        REQUIRE(!nkgt::is_vec3_like_v<vec3_xyz_methods>);
    }

    SECTION("Additional data members are ignored") {
        REQUIRE(nkgt::is_vec3_like_v<vec3_more_members>);
    }
}
