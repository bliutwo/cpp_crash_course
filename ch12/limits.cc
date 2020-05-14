#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <limits>

// Using std::numeric_limits<T>::min() to facilitate an int underflow.
// Although at press time the major compilers produce code that passes the
// test, this program contains undefined behavior.
//
// Such silent underflows have been the cause of untold numbers of software
// security vulnerabilities. Don't rely on this undefined behavior!
TEST_CASE("std::numeric_limits::min provides the smallest finite value.") {
    auto my_cup = std::numeric_limits<int>::min();
    auto underfloweth = my_cup - 1;
    REQUIRE(my_cup < underfloweth);
}
