#include <cstdio>
#include "primenumberrange.h"

int main() {
    for (const auto i : PrimeNumberRange{ 5000 }) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
