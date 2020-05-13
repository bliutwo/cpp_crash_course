#include <cstdio>
#include <cstdint>
#include <chrono>
#include "headers/Stopwatch.h"

int main() {
    const size_t n = 1'000'000;
    std::chrono::nanoseconds elapsed;
    {
        Stopwatch stopwatch{ elapsed };
        volatile double result{ 1.23e45 };
        for (double i = 1; i < n; i++) {
            result /= i;
        }
    }
    auto time_per_division = elapsed.count() / double{ n };
    printf("Took %gns per division.\n", time_per_division);
}
