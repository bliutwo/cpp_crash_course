#include "assert.h"
#include "braking.h"

void initial_speed_is_zero() {
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus }; // 1
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not equal 0"); // 2
}

void initial_sensitivity_is_five() {
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    assert_that(auto_brake.get_collision_threshold_s() == 5L,
                "sensitivity is not 5");
}

void sensitivity_greater_than_1() {
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    try {
        auto_brake.set_collision_threshold_s(0.5L);
    } catch (const std::exception&) {
        return;
    }
    assert_that(false, "no exception thrown");
}

// void speed_is_saved() {
//     AutoBrake auto_brake{ [](const BrakeCommand&) {} };
//     auto_brake.observe(SpeedUpdate{ 100L });
//     assert_that(100L == auto_brake.get_speed_mps(), "speed not saved to 100");
//     auto_brake.observe(SpeedUpdate{ 50L });
//     assert_that(50L == auto_brake.get_speed_mps(), "speed not saved to 50");
//     auto_brake.observe(SpeedUpdate{ 0L });
//     assert_that(0L == auto_brake.get_speed_mps(), "speed not saved to 0");
// }
//
// void alert_when_imminent() {
//     int brake_commands_published{};
//     AutoBrake auto_brake {
//         [&brake_commands_published](const BrakeCommand&) {
//             brake_commands_published++;
//         }
//     };
//     auto_brake.set_collision_threshold_s(10L);
//     auto_brake.observe(SpeedUpdate{ 100L });
//     auto_brake.observe(CarDetected{ 100L, 0L });
//     assert_that(brake_commands_published == 1, "brake commands published not one");
// }
//
// void no_alert_when_not_imminent() {
//     int brake_commands_published{};
//     AutoBrake auto_brake{
//         [&brake_commands_published](const BrakeCommand&) {
//             brake_commands_published++;
//         }
//     };
//     auto_brake.set_collision_threshold_s(2L);
//     auto_brake.observe(SpeedUpdate{ 100L });
//     auto_brake.observe(CarDetected{ 1000L, 50L });
//     assert_that(brake_commands_published == 0, "brake command published");
// }
