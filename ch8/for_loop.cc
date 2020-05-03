#include <cstdio>

int main() {
    const int x[]{ 1, 1, 2, 3, 5, 8 };
    printf("i: x[i]\n");
    for (int i{} /*3*/; i < 6 /*4*/; i++ /*5*/) {
        printf("%d: %d\n", i, x[i]);
    }
    return 0;
}
