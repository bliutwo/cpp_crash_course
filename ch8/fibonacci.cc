#include <cstdio>
#include "fibonacci.h"

int main() {
    for (const auto i : FibonacciRange{ 5000 }) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

int main1() {
    FibonacciRange range{ 5000 };
    const auto end = range.end();
    for (auto x = range.begin(); x != end; ++x) {
        auto i = *x;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
