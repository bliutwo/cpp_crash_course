#include "car_braking.h"

int main() {
    ServiceBus bus;
    AutoBrake auto_brake{ [&bus] (const auto& cmd) {
                            bus.publish(cmd);
                        }
    };
    while (true) { // Service bus's event loop
        auto_brake.observe(SpeedUpdate{ 10L });
        auto_brake.observe(CarDetected{ 250L, 25L });
    }
    return 0;
}
