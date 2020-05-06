#include <cstdio>

float add(float a, int b) {
    return a + b;
}

float subtract(float a, int b) {
    return a - b;
}

int main() {
    const float first{ 100 };
    const int second{ 20 };

    float(*operation)(float, int) {}; // 1
    printf("operation initialized to 0x%p\n", operation); // 2

    operation = &add; // 3
    printf("%add = 0x%p\n", operation); // 4
    printf("%g + %d = %g\n", first, second, operation(first, second)); // 5

    operation = subtract; // 6
    printf("&subtract = 0x%p\n", operation); // 7
    printf("%g - %d = %g\n", first, second, operation(first, second)); // 8
}
