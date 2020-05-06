#include <limits>
#include <cstdio>
#include <cstdint>

int main() {
    int64_t b = std::numeric_limits<int64_t>::max();
    int32_t c(b); // The compiler abides.
    if (c != b) printf("Narrowing conversion!\n");
    return 0;
}
