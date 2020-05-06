#include "assert.h"

int main() {
    assert_that(1 + 2 > 2, "Something is profoundly wrong with the universe."); // 3
    assert_that(24 == 42, "This assertion will generate an exception."); // 4
    return 0;
}
