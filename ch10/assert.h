#include <stdexcept>
constexpr void assert_that(bool statement, const char* message) {
    if (!statement /*1*/) throw std::runtime_error{ message }; // 2
}
