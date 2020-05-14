#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <array>

std::array<int, 10> static_array;

// Initializing a std::array. You might get compiler warnings from 
// REQUIRE(local_array[0] != 0); since local_array has uninitialized
// elements
TEST_CASE("std::array") {
    REQUIRE(static_array[0] == 0);

    SECTION("uninitialized without braced initializers") {
        std::array<int, 10> local_array;
        REQUIRE(local_array[0] != 0);
    }

    SECTION("initialized with braced initializers") {
        std::array<int, 10> local_array{ 1, 1, 2, 3 };
        REQUIRE(local_array[0] == 1);
        REQUIRE(local_array[1] == 1);
        REQUIRE(local_array[2] == 2);
        REQUIRE(local_array[3] == 3);
        REQUIRE(local_array[4] == 0);
    }
}

// Accessing elements of an array. Uncommenting // fib[4] = 5; will cause
// undefined behavior, whereas uncommenting // std::get<4>(fib); will cause
// compilation failure.
TEST_CASE("std::array access") {
    std::array<int, 4> fib{ 1, 1, 0, 3 };

    SECTION("operator[] can get and set elements") {
        fib[2] = 2;
        REQUIRE(fib[2] == 2);
        // fib[4] = 5;
    }

    SECTION("at() can get and set elements") {
        fib.at(2) = 2;
        REQUIRE(fib.at(2) == 2);
        REQUIRE_THROWS_AS(fib.at(4), std::out_of_range);
    }
    SECTION("get can get and set elements") {
        std::get<2>(fib) = 2;
        REQUIRE(std::get<2>(fib) == 2);
        // std::get<4>(fib);
    }
}

// Using the convenience methods front and back on a std::array
TEST_CASE("std::array has convenience methods") {
    std::array<int, 4> fib{ 0, 1, 2, 0 };

    SECTION("front") {
        fib.front() = 1;
        REQUIRE(fib.front() == 1);
        REQUIRE(fib.front() == fib[0]);
    }

    SECTION("back") {
        fib.back() = 3;
        REQUIRE(fib.back() == 3);
        REQUIRE(fib.back() == fib[3]);
    }
}
