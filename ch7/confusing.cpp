#include <cstdio>

int confusing(int &x) {
    return x = 9, x++, x / 2;
}

int main() {
    int x{};
    auto y = confusing(x);
    printf("x: %d\ny: %d\n", x, y); // x is 10, y is 5
    return 0;
}
