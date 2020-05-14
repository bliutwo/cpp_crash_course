#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <ratio>

TEST_CASE("std::ratio") {
    using ten = std::ratio<10, 1>;
    using two_thirds = std::ratio<2, 3>;
    using result = std::ratio_multiply<ten, two_thirds>;
    REQUIRE(result::num == 20);
    REQUIRE(result::den == 3);
}
