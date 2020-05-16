#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <bitset>

TEST_CASE("std::bitset supports integer initialization") {
    std::bitset<4> bs(0b1010);
    REQUIRE_FALSE(bs[0]);
    REQUIRE(bs[1]);
    REQUIRE_FALSE(bs[2]);
    REQUIRE(bs[3]);
}
