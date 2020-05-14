#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <stdexcept>
#include <optional>

template <typename To, typename From>
std::optional<To> narrow_cast (From value) {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if (value != backwards) {
        return std::nullopt;
    } else {
        return converted;
    }
}

TEST_CASE("narrow_cast an int to short, but return empty optional if narrowed") {
    int perfect{ 496 };
    const auto perfect_short = narrow_cast<short>(perfect);
    REQUIRE(perfect_short.has_value());
    int cyclic { 142857 };
    const auto cyclic_short = narrow_cast<short>(cyclic);
    REQUIRE_FALSE(cyclic_short.has_value());
}
