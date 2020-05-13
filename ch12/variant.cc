#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <variant>
#include "headers/EscapeCapsule.h"
#include "headers/BugblatterBeast.h"

TEST_CASE("std::variant") {
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    REQUIRE(hagunemnon.index() == 0);

    hagunemnon.emplace<EscapeCapsule>(600);
    REQUIRE(hagunemnon.index() == 1);

    REQUIRE(std::get<EscapeCapsule>(hagunemnon).weight_kg == 600);
    REQUIRE(std::get<1>(hagunemnon).weight_kg == 600);
    REQUIRE_THROWS_AS(std::get<0>(hagunemnon), std::bad_variant_access);
}
