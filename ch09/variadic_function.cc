#include <cstdio>
#include <cstdint>
#include <cstdarg>

int sum(size_t n, ... /*1*/) {
    va_list args; // 2
    va_start(args, n); // 3
    int result{};
    while (n--) {
        auto next_element = va_arg(args, int); // 4
        result += next_element;
    }
    va_end(args); // 5
    return result;
}

int main() {
    printf("The answer is %d.", sum(6, 2, 4, 6, 8, 10, 12)); // 6
}
