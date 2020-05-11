// Adding Google Mock to a third-party unit-testing framework

#include "braking.h"
#include "gmock/gmock.h"

struct MockServiceBus : IServiceBus {
    MOCK_METHOD1(publish, void(const BrakeCommand& cmd));
    MOCK_METHOD1(subscribe, void(SpeedUpdateCallback callback));
    MOCK_METHOD1(subscribe, void(CarDetectedCallback callback));
};

// TODO: where do I place this block?
/*
MockServiceBus naggy_mock;
::testing::NiceMock<MockServiceBus> nice_mock;
::testing::StrictMock<MockServiceBus> strict_mock;
*/


using ::testing::_;

// using ::testing::A;

using ::testing::Field;
using ::testing::DoubleEq;

TEST(AutoBrakeTest, PublishIsCalled) {
    MockServiceBus bus;
    EXPECT_CALL(bus, publish(_));
//     EXPECT_CALL(bus, publish(A<BrakeCommand>)); // TODO: why doesn't this work?
    EXPECT_CALL(bus, publish(Field(&BrakeCommand::time_to_collision_s,
                                   DoubleEq(1L)))).Times(1);
    // more to follow
}

int main(int argc, char** argv) {
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
    // Unit test as usual, Google Mock is initialized
    printf("Wow\n");
}
