#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "DeadMenOfDunharrow.h"
#include <memory>

int DeadMenOfDunharrow::oaths_to_fulfill{};
using UniqueOathBreakers = std::unique_ptr<DeadMenOfDunharrow>;

TEST_CASE("UniquePtr can be used in move") {
    auto aragorn = std::make_unique<DeadMenOfDunharrow>();
    SECTION("construction") {
        auto son_of_arathorn{ std::move(aragorn) };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment") {
        auto son_of_arathorn = std::make_unique<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = std::move(aragorn);
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}
