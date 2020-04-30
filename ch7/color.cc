#include <cstdint>

struct Color {
    float H, S, V;
};

constexpr uint8_t max(uint8_t a, uint8_t b) {
    return a > b ? a : b;
}
constexpr uint8_t min(uint8_t a, uint8_t b, uint8_t c) {
    return max(max(a, b), max(a, c));
}
