#include <cstdio>
#include "fibonacci.h"

int main() {
    for (auto i : FibonacciRange{ 5000 }) {
        if (i == 21) { // 1
            printf("*** "); // 2
            break; // 3
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
