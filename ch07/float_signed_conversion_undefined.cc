#include <limits>
#include <cstdio>

int main() {
    double x = std::numeric_limits<float>::max();
    long double y = std::numeric_limits<double>::max();
    float z = std::numeric_limits<long double>::max(); // Undefined behavior
    printf("x: %g\ny: %Lg\nz: %g\n", x, y, z);
    return 0;
}
