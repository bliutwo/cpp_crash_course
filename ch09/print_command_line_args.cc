#include <cstdio>
#include <cstdint>

int main(int argc, char** argv) { // 1
    printf("Arguments: %d\n", argc); // 2
    for (size_t i{}; i < argc; i++) {
        printf("%zd: %s\n", i, argv[i]); // 3
    }
    return 0;
}
