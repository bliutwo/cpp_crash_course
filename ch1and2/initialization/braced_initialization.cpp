#include<cstdio>

int main() {
    int i = {};
    printf("%d\n", i);
    int f { 42 };
    printf("%d\n", f);
    int g = {42};
    int h(42);
    printf("%d %d\n", g, h);
    return 0;
}
