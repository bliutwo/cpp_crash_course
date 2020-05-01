#include <cstdio>
#include <cstdint>

void randomize(uint32_t&); // 1

int main() {
    size_t iterations{}; // 2
    uint32_t number{ 0x4c4347 }; // 3
    while (number != 0x474343) { // 4
        randomize(number); // 5
        ++iterations; // 6
    }
    printf("%zd\n", iterations); // 7
}

void randomize(uint32_t& x) {
    x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000; // 8
}
