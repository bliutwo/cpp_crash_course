#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <cmath>
#include <boost/math/constants/constants.hpp>

TEST_CASE("boost::math offers constants") {
    using namespace boost::math::double_constants;
    auto sphere_volume = four_thirds_pi * std::pow(10, 3);
    REQUIRE(sphere_volume == Approx(4188.7902047));
}
