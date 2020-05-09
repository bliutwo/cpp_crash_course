#define BOOST_TEST_MODULE AutoBrakeTest
#include <boost/test/included/unit_test.hpp>
#include "braking.h"

BOOST_AUTO_TEST_CASE(InitialCarSpeedIsZero) {
    MockServiceBus bus{};
    AutoBrake auto_brake{ bus };
    BOOST_TEST(0 == auto_brake.get_speed_mps());
}
