#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <random>

TEST_CASE("mt19937_64 is pseudorandom") {
    std::mt19937_64 mt_engine{ 91586 };
    REQUIRE(mt_engine() == 8346843996631475880);
    REQUIRE(mt_engine() == 2237671392849523263);
    REQUIRE(mt_engine() == 7333164488732543658);
}
