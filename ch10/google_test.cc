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

struct AutoBrakeTest : ::testing::Test { // 1
    MockServiceBus bus{};
    AutoBrake auto_brake { bus };
};

TEST_F /*2*/(AutoBrakeTest/*3*/, InitialCarSpeedIsZero/*4*/) {
    ASSERT_FLOAT_EQ(0, auto_brake.get_speed_mps()); // 5
}

TEST_F(AutoBrakeTest, InitialSensitivityIsFive) {
    ASSERT_DOUBLE_EQ(5, auto_brake.get_collision_threshold_s());
}

TEST_F(AutoBrakeTest, SensitivityGreaterThanOne) {
    ASSERT_ANY_THROW(auto_brake.set_collision_threshold_s(0.5L)); // 6
}

TEST_F(AutoBrakeTest, SpeedIsSaved) {
    bus.speed_update_callback(SpeedUpdate{ 100L });
    ASSERT_EQ(100L, auto_brake.get_speed_mps());
    bus.speed_update_callback(SpeedUpdate{ 50L });
    ASSERT_EQ(50L, auto_brake.get_speed_mps());
    bus.speed_update_callback(SpeedUpdate{ 0L });
    ASSERT_EQ(0L, auto_brake.get_speed_mps());
}

TEST_F(AutoBrakeTest, NoAlertWhenNotImminent) {
    auto_brake.set_collision_threshold_s(2L);
    bus.speed_update_callback(SpeedUpdate{ 100L });
    bus.car_detected_callback(CarDetected{ 1000L, 50L });
    ASSERT_EQ(bus.commands_published, 0);
}

TEST_F(AutoBrakeTest, AlertWhenImminent) {
    auto_brake.set_collision_threshold_s(10L);
    bus.speed_update_callback(SpeedUpdate{ 100L });
    bus.car_detected_callback(CarDetected{ 100L, 0L });
    ASSERT_EQ(bus.commands_published, 1);
    ASSERT_DOUBLE_EQ(1L, bus.last_command.time_to_collision_s);
}
