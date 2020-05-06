#include <cstdio>
#include <cstdint>

bool double_return_overflow(uint8_t& x) { // 1
    const auto original = x;
    x *= 2;
    return original > x;
}

int main() {
    uint8_t x{ 1 }; // 2
    printf("uint8_t: \n===\n");
    while(!double_return_overflow(x) /*3*/) {
        printf("%u ", x); // 4
    }
    printf("\n");
    return 0;
}
