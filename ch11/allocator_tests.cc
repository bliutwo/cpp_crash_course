#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "DeadMenOfDunharrow.h"
#include "MyAllocator.h"

int DeadMenOfDunharrow::oaths_to_fulfill{};

TEST_CASE("Allocator") {
    auto message = "The way is shut.";
    MyAllocator<DeadMenOfDunharrow> alloc;
    {
        auto aragorn = std::allocate_shared<DeadMenOfDunharrow>(alloc,
                                                                message);
        REQUIRE(aragorn->message == message);
        REQUIRE(n_allocated == 1);
        REQUIRE(n_deallocated == 0);
    }
    REQUIRE(n_allocated == 1);
    REQUIRE(n_deallocated == 1);
}
