#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "DeadMenOfDunharrow.h"
#include <memory>

int DeadMenOfDunharrow::oaths_to_fulfill{};

TEST_CASE("WeakPtr lock() yields") {
    auto message = "The way is shut.";
    SECTION("a shared pointer when tracked object is alive") {
        auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
        std::weak_ptr<DeadMenOfDunharrow> legolas{ aragorn };
        auto sh_ptr = legolas.lock();
        REQUIRE(sh_ptr->message == message);
        REQUIRE(sh_ptr.use_count() == 2);
    }
    SECTION("empty when shared pointer empty") {
        std::weak_ptr<DeadMenOfDunharrow> legolas;
        {
            auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
            legolas = aragorn;
        }
        auto sh_ptr = legolas.lock();
        REQUIRE(nullptr == sh_ptr);
    }
}
