#include <cstdio>

int main() {
    int key_to_the_universe[]{ 3, 6, 9 };
    int* key_ptr = key_to_the_universe; // points to 3
    printf("key_to_the_universe: %d\n", *(key_ptr + 2));
    return 0;
}
