#include <cstdint>

int main() {
    auto x = 2.7182818284590452353602874713527L;
    // uint8_t y = x; // Silent truncation
    uint8_t y{ x }; // Bang!
}
