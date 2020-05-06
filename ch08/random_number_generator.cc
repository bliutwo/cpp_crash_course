#include <cstdio>
#include <cstdint>

struct RandomNumberGenerator {
    explicit RandomNumberGenerator(uint32_t seed)
        : iterations{}/*1*/, number{ seed }/*2*/ {}
    uint32_t next(); // 3
    size_t get_iterations() const; // 4
private:
    size_t iterations;
    uint32_t number;
};

int main() {
    RandomNumberGenerator rng{ 0x4c4347 }; // 5
    while (rng.next() != 0x474343) { // 6
        // Do nothing...
    }
    printf("%zd\n", rng.get_iterations()); // 7
}

uint32_t RandomNumberGenerator::next() { // 8
    ++iterations;
    number = 0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
    return number;
}

size_t RandomNumberGenerator::get_iterations() const { // 9
    return iterations;
}
