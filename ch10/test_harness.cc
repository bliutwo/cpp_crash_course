#include "run_test.h"
#include "unit_tests.h"

int main() {
    run_test(initial_speed_is_zero, "initial speed is 0");
    run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
    run_test(sensitivity_greater_than_1, "sensitivity greater than 1");
    // run_test(speed_is_saved, "speed is saved");
    // run_test(alert_when_imminent, "alert when imminent");
    // run_test(no_alert_when_not_imminent, "no alert when imminent");
}
