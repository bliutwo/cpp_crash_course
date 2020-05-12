#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <boost/scoped_array.hpp>

TEST_CASE("ScopedArray supports operator[]") {
    boost::scoped_array<int> squares {
        new int[5] { 0, 4, 9, 16, 25 }
    };
    squares[0] = 1;
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}
