#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <memory>

TEST_CASE("UniquePtr to array supports operator[]") {
    std::unique_ptr<int[]> squares {
        new int[5]{ 1, 4, 9, 16, 25 }
    };
    squares[0] = 1;
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}
