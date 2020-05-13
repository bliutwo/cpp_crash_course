#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <optional>
#include "headers/TheMatrix.h"

std::optional<TheMatrix> take(Pill pill) {
    if (pill == Pill::Blue) return TheMatrix{ 6 };
    return std::nullopt;
}

TEST_CASE("std::optional contains types") {
    if (auto matrix_opt = take(Pill::Blue)) {
        REQUIRE(matrix_opt->iteration == 6);
        auto& matrix = matrix_opt.value();
        REQUIRE(matrix.iteration == 6);
    } else {
        FAIL("The optional evaluated to false.");
    }
}

TEST_CASE("std::optional can be empty") {
    auto matrix_opt = take(Pill::Red);
    if (matrix_opt) FAIL("The Matrix is not empty.");
    REQUIRE_FALSE(matrix_opt.has_value());
}
