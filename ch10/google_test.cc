// NOTE: The commands for running this shit is the following:
//
// cmake .
//
// make
//
// That's it! I wish somewhere it was said to do that. Glad I finally
// figured it out, though.

#include "gtest/gtest.h"
#include "braking.h"

TEST(AutoBrake, InitialCarSpeedIsZero) {
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    ASSERT_FLOAT_EQ(0, auto_brake.get_speed_mps());
}
