#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <complex>

TEST_CASE("std::complex has a real and imaginary component") {
    std::complex<double> a{0.5, 14.13};
    REQUIRE(std::real(a) == Approx(0.5));
    REQUIRE(std::imag(a) == Approx(14.13));
}
