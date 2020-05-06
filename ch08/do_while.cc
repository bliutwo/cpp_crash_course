#include <cstdio>
#include <cstdint>

bool double_return_overflow(uint8_t& x) { // 1
    const auto original = x;
    x *= 2;
    return original > x;
}

int main() {
    uint8_t x{ 1 };
    printf("uint8_t:\n===\n");
    do {
        printf("%u ", x); // 1
    } while (!double_return_overflow(x) /*2*/);
    printf("\n");
    return 0;
}
