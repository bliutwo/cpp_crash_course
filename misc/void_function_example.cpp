#include <cstdio>

void add_one(int& i) {
    i++;
}

int main() {
    int i = 0;
    printf("i: %d\n", i);
    add_one(i);
    printf("i after adding one: %d\n", i);
    return 0;
}

