// The std::any and std::any_cast allow you to extract concrete types

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <any>
#include "headers/EscapeCapsule.h"

TEST_CASE("std::any allows us to std::any_cast into a type") {
    std::any hagunemnon;
    hagunemnon.emplace<EscapeCapsule>(600);
    auto capsule = std::any_cast<EscapeCapsule>(hagunemnon);
    REQUIRE(capsule.weight_kg == 600);
    REQUIRE_THROWS_AS(std::any_cast<float>(hagunemnon), std::bad_any_cast);
}
