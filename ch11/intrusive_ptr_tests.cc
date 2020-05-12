#define CATCH_CONFIG_MAIN
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include "../catch.hpp"
#include "DeadMenOfDunharrow.h"

int DeadMenOfDunharrow::oaths_to_fulfill{};
using IntrusivePtr = boost::intrusive_ptr<DeadMenOfDunharrow>;
size_t ref_count{};

void intrusive_ptr_add_ref(DeadMenOfDunharrow* d) {
    ref_count++;
}

void intrusive_ptr_release(DeadMenOfDunharrow* d) {
    ref_count--;
    if (ref_count == 0) delete d;
}

TEST_CASE("IntrusivePtr uses an embedded reference counter.") {
    REQUIRE(ref_count == 0);
    IntrusivePtr aragorn{ new DeadMenOfDunharrow{} };
    REQUIRE(ref_count == 1);
    {
        IntrusivePtr legolas{ aragorn };
        REQUIRE(ref_count == 2);
    }
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}
