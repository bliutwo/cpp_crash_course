#include <cstdio>
#include <array>

int main() {
    std::array<int, 4> arr{ 1, 2, 3, 4 };
    printf("The third element is %d.\n", arr[2]);
    arr[2] = 100;
    printf("The third element is %d.\n", arr[2]);
}
