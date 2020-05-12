#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "braking.h"

// TEST_CASE("AutoBrake") {
//     // Unit test here
// }

// TEST_CASE ("initial car speed is zero") {
//     MockServiceBus bus{};
//     AutoBrake auto_brake{ bus };
//     REQUIRE(auto_brake.get_speed_mps() == 0);
// }
//
// TEST_CASE("AutoBrake") {
//     MockServiceBus bus{};
//     AutoBrake auto_brake{ bus };
//     REQUIRE(auto_brake.get_collision_threshold_s() == Approx(5L));
// }

TEST_CASE("AutoBrake" /*1*/) {
    MockServiceBus bus{}; // 2
    AutoBrake auto_brake{ bus }; // 3

    SECTION/*4*/("initializes speed to zero"/*5*/) {
        REQUIRE(auto_brake.get_speed_mps() == Approx(0));
    }

    SECTION("initializes sensitivity to five") {
        REQUIRE(auto_brake.get_collision_threshold_s() == Approx(5));
    }

    SECTION("throws when sensitivity less than one") {
        REQUIRE_THROWS(auto_brake.set_collision_threshold_s(0.5L));
    }

    SECTION("saves speed after update") {
        bus.speed_update_callback(SpeedUpdate{ 100L });
        REQUIRE(100L == auto_brake.get_speed_mps());
        bus.speed_update_callback(SpeedUpdate{ 50L });
        REQUIRE(50L == auto_brake.get_speed_mps());
        bus.speed_update_callback(SpeedUpdate{ 0L });
        REQUIRE(0L == auto_brake.get_speed_mps());
    }

    SECTION("no alert when not imminent") {
        auto_brake.set_collision_threshold_s(2L);
        bus.speed_update_callback(SpeedUpdate{ 100L });
        bus.car_detected_callback(CarDetected{ 1000L, 50L });
        REQUIRE(bus.commands_published == 0);
    }

    SECTION("alert when imminent") {
        auto_brake.set_collision_threshold_s(10L);
        bus.speed_update_callback(SpeedUpdate{ 100L });
        bus.car_detected_callback(CarDetected{ 100L, 0L });
        REQUIRE(bus.commands_published == 1);
        REQUIRE(bus.last_command.time_to_collision_s == Approx(1));
    }
}
