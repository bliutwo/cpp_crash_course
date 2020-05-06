#include "assert.h"

void initial_speed_is_zero() {
    AutoBrake auto_brake{ [](const BrakeCommand&) {} }; // 1
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not equal 0"); // 2
}
