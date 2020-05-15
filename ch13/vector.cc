#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>

TEST_CASE("std::vector supports default construction") {
    std::vector<const char*> vec;
    REQUIRE(vec.empty());
}

TEST_CASE("std::vector supports braced initialization") {
    std::vector<int> fib{ 1, 1, 2, 3, 5 };
    REQUIRE(fib[4] == 5);
}

TEST_CASE("std::vector supports") {
    SECTION("braced initialization") {
        std::vector<int> five_nine{ 5, 9 };
        REQUIRE(five_nine[0] == 5);
        REQUIRE(five_nine[1] == 9);
    }
    SECTION("fill constructor") {
        std::vector<int> five_nines(5, 9);
        REQUIRE(five_nines[0] == 9);
        REQUIRE(five_nines[4] == 9);
    }
}

TEST_CASE("std::vector supports construction from iterators") {
    std::array<int, 5> fib_arr{ 1, 1, 2, 3, 5 };
    std::vector<int> fib_vec(fib_arr.begin(), fib_arr.end());
    REQUIRE(fib_vec[4] == 5);
    REQUIRE(fib_vec.size() == fib_arr.size());
}
